#!/bin/bash

cd ../../build

./ZTableGenerator -i ../include -c ../test/test1/config.json -f ../test/test1/out/FA.md -t ../test/test1/parseTable.md -p ../test/test1/parse.cpp    

./ZParser -i ../test/test1/token.txt -t ../test/test1/parseTable.md -o ../test/test1/out/CST.md -p ../test/test1/out/process.md 2> error.txt


