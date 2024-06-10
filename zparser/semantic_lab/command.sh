#!/bin/bash

rm -f ./log.txt
rm -f ./out/code_target.md

../build/ZTableGenerator \
    -i ../include\
    -c ./formal/test.json \
    -f ./out/FA.md \
    -t ./out/table.md \
    -p ./out/parse.cpp


./ZParser -i ./formal/token.txt \
    -t ./out/table.md \
    -o ./out/CST.md \
    -p ./out/process.md \
    -c ./out/code_target.md > log.txt 2>&1
