#!/bin/bash

RED='\033[0;31m'
NC='\033[0m'
GREEN='\033[0;32m'

make fclean > /dev/null

for f in tests/*.cpp; do
	if [ $f = "*.cpp" ]; then
		break
	fi
	echo "${RED}Compiling ${GREEN}" $(basename $f) "${NC}"
	make MAIN=$f > /dev/null
	echo "${RED}Running test ${GREEN}" $(basename $f) "${NC}"
	./a.out
	make MAIN=$f fclean > /dev/null
done
