#!/bin/bash

if [ "$#" -le 1 ]; then
    echo "USAGE: $0 host port"
    exit 0
fi

USERNAME="Anonymous"
PASS=""

HOST=$1
PORT=$2
VERBOSE=${3:0}
MKFIFO=`which mkfifo`
PIPE=fifo
OUT=outfile
TAIL=`which tail`
NC="`which nc` -C"
TIMEOUT=1 #max time before reading server response
err=0

getcode() {
  sleep $TIMEOUT
  local code=$1
  if [[ VERBOSE -eq 1 ]]; then
    echo "Waiting for $code reply-code"
  fi
  local data=`$TAIL -n 1 $OUT |cat -e |grep "^$code.*[$]$" |wc -l`
  return $data
}
print_failed() {
    echo -e "\033[1;31m$1 test failed\033[0m"
    echo -e "\033[1;31mExpected reply-code: $2\033[0m"
    echo -e "\033[1;31mReceived : ["`$TAIL -n 1 $OUT| cat -e`"]\033[0m"
    echo -e "\033[1;31mKO\033[0m"
    ((err++))
}
print_succeeded() {
  #echo "$1 test succeeded"
  #echo "OK"
  kill_client 2>&1 >/dev/null
}
launch_client() {
  local host=$1
  local port=$2

  $MKFIFO $PIPE
  ($TAIL -f $PIPE 2>/dev/null | $NC $host $port &> $OUT &) >/dev/null 2>/dev/null

  echo "Connecting to $host : $port"
  sleep $TIMEOUT
  getcode 220
  if [[ $? -eq 1 ]]; then
    echo -e "Reply-code \033[1;32mOK\033[0m"
    return 1
  else
    echo -e "\033[1;31mConnection to $host:$port failed\033[0m"
    echo -e "\033[1;31mExpected reply-code: 220\033[0m"
    echo -e "\033[1;31mReceived : ["`tail -n 1 $OUT |cat -e`"]\033[0m"
    return 0
  fi
}
launch_test() {
  local test_name=$1
  local cmd=$2
  local code=$3

  if [[ VERBOSE -eq 1 ]]; then
    echo "Sending [$cmd^M$]"
  fi
  echo "$cmd" >$PIPE
  getcode $code
  if [[ ! $? -eq 1 ]]; then
    print_failed "$test_name" "$code"
    kill_client
    clean
    echo -e "$cmd \033[1;31mKO\033[0m"
    return
  fi
  echo -e "$cmd \033[1;32mOK\033[0m"
}
kill_client() {
  local nc=`which nc`

  if [ `pidof $TAIL | wc -l` -ne 0 ]
  then
    killall $TAIL &>/dev/null
  fi
  if [ `pidof $nc | wc -l` -ne 0 ]
  then
    killall $nc &>/dev/null
  fi
  rm -f $PIPE $OUT &> /dev/null
}
clean() {
  rm -f $PIPE $OUT log &>/dev/null
}

# Simple authentication with USER + PASS command
test_auth() {
  local test_name="Authentication"

  local cmd1="USER $USERNAME"
  local cmd2="PASS $PASS"

  echo -e "\033[1;37m-----[$test_name]-----\033[0m"
  launch_client $HOST $PORT
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client
    return
  fi

  launch_test "$test_name" "$cmd1" 331
  launch_test "$test_name" "$cmd2" 230

  print_succeeded "$test_name"
  return
}
test_auth_advanced() {
  local test_name="Authentication Advanced"

  local cmd1="USER $USERNAME"
  local cmd2="PASS dfdddf"
  local cmd3="PASS $PASS"

  echo -e "\033[1;37m-----[$test_name]-----\033[0m"
  launch_client $HOST $PORT
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client
    return
  fi

  launch_test "$test_name" "$cmd1" 331
  launch_test "$test_name" "$cmd2" 530
  launch_test "$test_name" "$cmd3" 530
  launch_test "$test_name" "$cmd1" 331
  launch_test "$test_name" "$cmd3" 230

  print_succeeded "$test_name"
  return
}
test_auth_middleware() {
  local test_name="Authentification Middleware"

  local cmd1="NOOP"
  local cmd2="USER $USERNAME"
  local cmd3="PASS $PASS"

  echo -e "\033[1;37m-----[$test_name]-----\033[0m"
  launch_client $HOST $PORT
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client
    return
  fi

  launch_test "$test_name" "$cmd1" 530
  launch_test "$test_name" "$cmd2" 331
  launch_test "$test_name" "$cmd3" 230
  launch_test "$test_name" "$cmd1" 200

  print_succeeded "$test_name"
  return
}

# Tests Commands
test_noop() {
  local test_name="Cmd:: Noop"

  local cmd1="USER $USERNAME"
  local cmd2="PASS $PASS"
  local cmd3="NOOP"

  echo -e "\033[1;37m-----[$test_name]-----\033[0m"
  launch_client $HOST $PORT
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client
    return
  fi

  launch_test "$test_name" "$cmd1" 331
  launch_test "$test_name" "$cmd2" 230
  launch_test "$test_name" "$cmd3" 200

  print_succeeded "$test_name"
  return
}
test_help() {
  local test_name="Cmd:: Help"

  local cmd1="USER $USERNAME"
  local cmd2="PASS $PASS"
  local cmd3="HELP"

  echo -e "\033[1;37m-----[$test_name]-----\033[0m"
  launch_client $HOST $PORT
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client
    return
  fi

  launch_test "$test_name" "$cmd1" 331
  launch_test "$test_name" "$cmd2" 230
  launch_test "$test_name" "$cmd3" 214

  print_succeeded "$test_name"
  return
}
test_quit() {
  local test_name="Cmd:: Quit"

  local cmd1="QUIT"

  echo -e "\033[1;37m-----[$test_name]-----\033[0m"
  launch_client $HOST $PORT
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client
    return
  fi

  launch_test "$test_name" "$cmd1" 221

  print_succeeded "$test_name"
  return
}
test_pwd() {
  local test_name="Cmd:: PWD"

  local cmd1="USER $USERNAME"
  local cmd2="PASS $PASS"
  local cmd3="PWD"

  echo -e "\033[1;37m-----[$test_name]-----\033[0m"
  launch_client $HOST $PORT
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client
    return
  fi

  launch_test "$test_name" "$cmd1" 331
  launch_test "$test_name" "$cmd2" 230
  launch_test "$test_name" "$cmd3" 257

  print_succeeded "$test_name"
  return
}
test_cwd() {
  local test_name="Cmd:: CWD"

  local cmd1="USER $USERNAME"
  local cmd2="PASS $PASS"
  local cmd3="CWD src"
  local cmd4="CWD sdsdss"
  local cmd5="CWD "

  echo -e "\033[1;37m-----[$test_name]-----\033[0m"
  launch_client $HOST $PORT
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client
    return
  fi

  launch_test "$test_name" "$cmd1" 331
  launch_test "$test_name" "$cmd2" 230
  launch_test "$test_name" "$cmd3" 250
  launch_test "$test_name" "$cmd4" 550
  launch_test "$test_name" "$cmd5" 550

  print_succeeded "$test_name"
  return
}
test_cdup() {
  local test_name="Cmd:: CDUP"

  local cmd1="USER $USERNAME"
  local cmd2="PASS $PASS"
  local cmd3="CDUP"

  echo -e "\033[1;37m-----[$test_name]-----\033[0m"
  launch_client $HOST $PORT
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client
    return
  fi

  launch_test "$test_name" "$cmd1" 331
  launch_test "$test_name" "$cmd2" 230
  launch_test "$test_name" "$cmd3" 250

  print_succeeded "$test_name"
  return
}
test_port() {
  local test_name="Cmd:: PORT"

  local cmd1="USER $USERNAME"
  local cmd2="PASS $PASS"
  local cmd3="PORT ffdfddv"
  local cmd4="PORT 0,10,0,0,23,23"

  echo -e "\033[1;37m-----[$test_name]-----\033[0m"
  launch_client $HOST $PORT
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client
    return
  fi

  launch_test "$test_name" "$cmd1" 331
  launch_test "$test_name" "$cmd2" 230
  launch_test "$test_name" "$cmd3" 500
  launch_test "$test_name" "$cmd4" 200

  print_succeeded "$test_name"
  return
}
test_pasv() {
  local test_name="Cmd:: PASV"

  local cmd1="USER $USERNAME"
  local cmd2="PASS $PASS"
  local cmd3="PASV"

  echo -e "\033[1;37m-----[$test_name]-----\033[0m"
  launch_client $HOST $PORT
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client
    return
  fi

  launch_test "$test_name" "$cmd1" 331
  launch_test "$test_name" "$cmd2" 230
  launch_test "$test_name" "$cmd3" 227

  print_succeeded "$test_name"
  return
}

test_list() {
  local test_name="Cmd:: LIST"

  local cmd1="USER $USERNAME"
  local cmd2="PASS $PASS"
  local cmd3="LIST"

  echo -e "\033[1;37m-----[$test_name]-----\033[0m"
  launch_client $HOST $PORT
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client
    return
  fi

  launch_test "$test_name" "$cmd1" 331
  launch_test "$test_name" "$cmd2" 230
  launch_test "$test_name" "$cmd3" 425

  print_succeeded "$test_name"
  return
}

# Test Special case
test_case_only_space()
{
    local test_name="CASE:: ONLY SPACE"

    local cmd1="      "

    echo -e "\033[1;37m-----[$test_name]-----\033[0m"
    launch_client $HOST $PORT
    if [[ ! $? -eq 1 ]]; then
      echo "KO"
      kill_client
      return
    fi

    launch_test "$test_name" "$cmd1" 530

    print_succeeded "$test_name"
    return
}
test_empty()
{
    local test_name="CASE:: EMPTY"

    local cmd1=""

    echo -e "\033[1;37m-----[$test_name]-----\033[0m"
    launch_client $HOST $PORT
    if [[ ! $? -eq 1 ]]; then
      echo "KO"
      kill_client
      return
    fi

    launch_test "$test_name" "$cmd1" 530

    print_succeeded "$test_name"
    return
}

test_auth
test_auth_advanced
test_auth_middleware

test_noop
test_help
test_quit
test_pwd
test_cwd
test_cdup
test_port
test_pasv
test_list

test_case_only_space
test_empty

clean
## RETURN ERROR
if [ $err -ne 0 ]; then
    exit 84
fi
