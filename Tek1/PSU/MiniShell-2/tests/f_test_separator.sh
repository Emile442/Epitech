#! /bin/bash
# Emile LEPETIT <emile.lepetit@epitech.eu>

## TEST SEPARATOR
bin_path="mysh"
tmp_foler="trace/tmp"
name="separator"
test_log="${tmp_foler}/${name}"
err=0

## Separator command
echo "ls -l; echo Bonjour" | /bin/tcsh > "${test_log}_separator.ref"
echo "ls -l; echo Bonjour" | ./$bin_path > "${test_log}_separator.out"
if [[ $(diff "${test_log}_separator.out" "${test_log}_separator.ref") = "" ]]; then
    echo "Separator: OK!"
else
    echo "Separator: KO!"
    ((err++))
fi

## RETURN ERROR
if [ $err -ne 0 ]; then
    exit 84
fi
