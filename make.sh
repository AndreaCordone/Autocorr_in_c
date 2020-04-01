#!/bin/bash 
g++ -I$mkBoostInc -c autocorr.cpp
g++ -L$mkBoostLib -lboost_iostreams -lboost_system -lboost_filesystem autocorr.o
./a.out
