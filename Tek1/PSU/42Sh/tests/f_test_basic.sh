#! /bin/bash
# Emile LEPETIT <emile.lepetit@epitech.eu>

## TEST BASIC
bin_path="42sh"
tmp_foler="trace/tmp"
name="basic"
test_log="${tmp_foler}/${name}"
err=0


## Empty command
echo "" | /bin/tcsh >> "${test_log}_empty.ref"
echo "" | ./$bin_path > "${test_log}_empty.out"
if [[ $(diff "${test_log}_empty.out" "${test_log}_empty.ref") = "" ]]; then
    echo "Command-Empty: OK!"
else
    echo "Command-Empty: KO!"
    ((err++))
fi

## ls commmand
echo "ls -l" | /bin/tcsh > "${test_log}_wrong.ref"
echo "ls -l" | ./$bin_path > "${test_log}_wrong.out"
if [[ $(diff "${test_log}_wrong.out" "${test_log}_wrong.ref") = "" ]]; then
    echo "Command-Wrong: OK!"
else
    echo "Command-Wrong: KO!"
    ((err++))
fi

## Wrong commmand
echo "ssss" | ./$bin_path > "${test_log}_wrong.out"
if [[ $(cat "${test_log}_wrong.out" | grep "ssss: Command not found.") != "" ]]; then
    echo "Command-Wrong: OK!"
else
    echo "Command-Wrong: KO!"
    ((err++))
fi

## RETURN ERROR
if [ $err -ne 0 ]; then
    exit 84
fi
