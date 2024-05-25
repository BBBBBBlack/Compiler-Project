#!/bin/bash

cd ../../build

token_file="../test/four_operations/token.txt"
parse_table_file="../test/four_operations/out/parse_table.md"
CST="../test/four_operations/out/CST.md"
process_file="../test/four_operations/out/process.md"
log_file="../test/four_operations/out/log.txt"

if [ "$1" = "right" ]; then
    token_file="../test/four_operations/token.txt"
elif [ "$1" = "error" ]; then
    token_file="../test/four_operations/token_error.txt"
    CST="../test/four_operations/out/CST_error.md"
    process_file="../test/four_operations/out/process_error.md"
    log_file="../test/four_operations/out/log_error.txt"
else
    echo "Invalid argument. Please provide 'right' or 'error'."
    exit 1
fi

./ZTableGenerator -i ../include \
    -c ../test/four_operations/config.json \
    -f ../test/four_operations/out/FA.md \
    -t $parse_table_file \
    -p ../test/four_operations/out/parse.cpp    

./ZParser -i $token_file \
    -t $parse_table_file \
    -o $CST \
    -p $process_file \
    > $log_file
