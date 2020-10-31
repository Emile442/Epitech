#!/bin/sh

echo "==========[BSQ_TESTS]=========="
echo "------[TEST CLEAN & INIT]------"
rm -rf tf_trace
mkdir tf_trace
echo "tmp_folder: OK"
rm trace.log
touch trace.log
echo "trace: OK"
echo " "

echo "-----------[BUILD]-------------"
make re
echo " "

echo "==========[TRACE_BSQ]==========" >> trace.log
echo $(date '+%d/%m/%Y %H:%M:%S') >> trace.log
echo " " >> trace.log
echo "------------[TRACE]------------"
echo " "

for file in maps-intermediate/mouli_maps/*; do
    echo "------" >> trace.log
    echo "------"
    # timeout 20 ./bsq maps-intermediate/mouli_maps/${file##*/} > tf_trace/${file##*/}
    timeout 60 ./bsq maps-intermediate/mouli_maps/${file##*/} > tf_trace/${file##*/}
    if [[ $(diff tf_trace/${file##*/} maps-intermediate/mouli_maps_solved/${file##*/}) = "" ]]; then
        echo "${file##*/}: SUCCESS!" >> trace.log
        echo "${file##*/}: SUCCESS!"
    else
        echo "${file##*/}: ERROR!" >> trace.log
        echo "${file##*/}: ERROR!"
    fi
    echo " " >> trace.log
    echo " " >> trace.log
    echo " "
    echo " "
done