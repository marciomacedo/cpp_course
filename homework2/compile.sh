#!/bin/sh
clear
rm -f *.o main
g++ -g -c graph.cpp
g++ -g main.cpp -o main graph.o
