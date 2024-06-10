#!/usr/bin/env bash

gcc $@ -o ./main
echo ""
./main
rm -rf ./main