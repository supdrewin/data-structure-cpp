#!/bin/zsh

export LANG=en_US.UTF-8

clear

for arg in '' 'CROSS=1'; do
	echo "\e[33;1m$(date) - Making $2 by $USER...\e[0;36m"

	for dir in $(find test -maxdepth 2 -type d); do
		make -C $dir PREFIX=$1 $arg $2
	done
done
