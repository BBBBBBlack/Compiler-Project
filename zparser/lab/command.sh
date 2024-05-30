#!/bin/bash

rm -f ./log.txt

../build/ZTableGenerator \
    -i ../include\
    -c ./in/semantic/test1.json \
    -f ./out/FA.md \
    -t ./out/table.md \
    -p ./out/parse.cpp


./ZParser -i ./in/semantic/sample_in1_token.txt \
    -t ./out/table.md \
    -o ./out/CST.md \
    -p ./out/process.md > log.txt 2>&1
