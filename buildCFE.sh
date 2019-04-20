#!/bin/bash
cd cFE
source setvars.sh
cd build/cpu1
make realclean
make config
make
cd ../../..
