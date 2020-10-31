#! /bin/bash
# Emile LEPETIT <emile.lepetit@epitech.eu>

## VARS
path=$1
bin="mysh"
bin_path="$1/$bin"
script_path="tests/f_test"
err=0

## ------TESTS----------
TEST_ARRAY=(
  basic
  error
  env
)
#-----------------------
COUNT=${#TEST_ARRAY[@]}

## ERROR HANDLING & USAGE
if [ -z $1 ]; then
    echo "USAGE: ./test_minishell.sh [shell_path]" 1>&2
    exit 84
fi

## TRACE FOLDER
rm -Rf trace 2>/dev/null
mkdir trace 2>/dev/null
mkdir trace/tmp 2>/dev/null

## BUILD
make -C $path > trace/build.log

if [ -f "$path/$bin" ]; then
    echo "---BUILD SUCCESS---"
    echo "---BUILD SUCCESS---" >> trace/build.log
else
    echo "---BUILD FAILED---" 1>&2
    echo "---BUILD FAILED---" >> trace/build.log
    echo "BIN: '$bin' was not found" 1>&2
    echo "You can see the trace log:" 1>&2
    echo "    trace/" 1>&2
    exit 84
fi

## TEST
echo "---TESTS RUN....---"
for ((i=0; i<$COUNT; i++)); do
    TEST_NAME=${TEST_ARRAY[i]}
    printf "${TEST_NAME}: Running..."
    "./${script_path}_${TEST_NAME}.sh" > "trace/test_${TEST_NAME}.log"
    if [ $? -ne 0 ]; then
        ((err++))
        printf "\033[1;31mKO!\033[0m\n"
    else
        printf "\033[1;32mOK!\033[0m\n"

    fi
done
echo "-----END TESTS-----"

## RETURN ERROR
if [ $err -ne 0 ]; then
    exit 84
fi
