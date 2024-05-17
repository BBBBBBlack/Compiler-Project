#!/bin/bash

../build/ZTableGenerator \
    -i ../include\
    -c ./in/config.json \
    -f ./out/FA.md \
    -t ./out/table.md \
    -p ./out/parse.cpp


./ZParser -i ./in/sample_in1_token.txt \
    -t ./out/table.md \
    -o ./out/CST.md \
    -p ./out/process.md