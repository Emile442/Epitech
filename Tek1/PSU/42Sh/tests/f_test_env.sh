#! /bin/bash
# Emile LEPETIT <emile.lepetit@epitech.eu>

## TEST ENV
bin_path="42sh"
tmp_foler="trace/tmp"
name="env"
test_log="${tmp_foler}/${name}"
err=0

## env
echo "env" | ./$bin_path > "${test_log}_env.out"
if [[ $(cat "${test_log}_env.out" | grep "HOME=") != "" ]]; then
    echo "Env-Home: OK!"
else
    echo "Error-Home: KO!"
    ((err++))
fi

## setenv
echo "setenv EMILE LOL\nenv" | ./$bin_path > "${test_log}_setenv.out"
if [[ $(cat "${test_log}_setenv.out" | grep "EMILE=LOL") != "" ]]; then
    echo "Env-Setenv: OK!"
else
    echo "Error-Setenv: KO!"
    ((err++))
fi

## unsetenv
echo "setenv EMILE LOL\nunsetenv EMILE\nenv" | ./$bin_path > "${test_log}_unsetenv.out"
if [[ $(cat "${test_log}_unsetenv.out" | grep "EMILE") == "" ]]; then
    echo "Env-UnSetenv: OK!"
else
    echo "Error-UnSetenv: KO!"
    ((err++))
fi

## RETURN ERROR
if [ $err -ne 0 ]; then
    exit 0
fi
