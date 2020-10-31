#! /bin/bash
# Emile LEPETIT <emile.lepetit@epitech.eu>

## TEST ERROR
bin_path="./mysh"
tmp_foler="trace/tmp"
name="error"
test_log="${tmp_foler}/${name}"
err=0

## floating Exception
gcc tests/bin/err_floating.c -o err_floating.test 2>/dev/null
echo "./err_floating.test" | ./$bin_path > "${test_log}_floating.out"
rm err_floating.test
if [[ $(cat "${test_log}_floating.out" | grep "Floating exception") != "" ]]; then
    echo "Error-Floating: OK!"
else
    echo "Error-Floating: KO!"
    ((err++))
fi

## Segmention Exception
gcc tests/bin/err_segfault.c -o err_segfault.test 2>/dev/null
echo "./err_segfault.test" | ./$bin_path > "${test_log}_err_segfault.out"
rm err_segfault.test
if [[ $(cat "${test_log}_err_segfault.out" | grep "Segmentation fault") != "" ]]; then
    echo "Error-Segmentation: OK!"
else
    echo "Error-Segmentation: KO!"
    ((err++))
fi

## Permission Denied
echo "./lib" | ./$bin_path > "${test_log}_err_permission.out"
if [[ $(cat "${test_log}_err_permission.out" | grep "Permission denied") != "" ]]; then
    echo "Error-Permission: OK!"
else
    echo "Error-Permission: KO!"
    ((err++))
fi

## RETURN ERROR
if [ $err -ne 0 ]; then
    exit 84
fi
