#!/bin/zsh

for dir in $(find test -maxdepth 2 -type d); do
	make -C $dir PREFIX=$1 CROSS=1 $2
	make -C $dir PREFIX=$1 $2
done
