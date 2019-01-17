#!/bin/sh
make > log
./../a.out text/alpha.txt | cat -e > t1 && cat text/alpha.txt | cat -e > t2 && diff t1 t2
./../a.out text/4n | cat -e > t1 && cat text/4n | cat -e > t2 && diff t1 t2
./../a.out text/blank | cat -e > t1 && cat text/blank | cat -e > t2 && diff t1 t2
./../a.out text/space | cat -e > t1 && cat text/space | cat -e > t2 && diff t1 t2
./../a.out text/special | cat -e > t1 && cat text/special | cat -e > t2 && diff t1 t2
./../a.out text/m3o | cat -e > t1 && cat text/m3o | cat -e > t2 && diff t1 t2
rm -f ../a.out 
make lftclean > log
rm t1 t2 log
