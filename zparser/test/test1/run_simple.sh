#!/bin/bash

cd ../../build

./ZTableGenerator -i ../include -c ../test/test1/config_simple.json -f ../test/test1/out/FA_simple.md -t ../test/test1/parseTable_simple.md -p ../test/test1/parse_simple.cpp    

./ZParser -i ../test/test1/token_simple.txt -t ../test/test1/parseTable_simple.md -o ../test/test1/out/CST_simple.md -p ../test/test1/out/process_simple.md 2> error.txt


