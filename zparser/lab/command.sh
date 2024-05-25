#!/bin/bash

rm -f ./log.txt

../build/ZTableGenerator \
    -i ../include\
    -c ./in/config_include_error.json \
    -f ./out/FA.md \
    -t ./out/table.md \
    -p ./out/parse.cpp


./ZParser -i ./in/sample_in1_token.txt \
    -t ./out/table.md \
    -o ./out/CST.md \
    -p ./out/process.md > log.txt 2>&1
