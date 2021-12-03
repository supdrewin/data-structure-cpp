#!/bin/bash

export LANG=en_US.UTF-8 OWNER=Supdrewin

clear

[[ $2 = lib ]] && make -C src PREFIX="$1" "$3" && exit

echo -e "\e[33;1m$(date) - Making ${PWD##*/} by $OWNER...\e[0;36m"

while read -rd '' dir; do
	make -C "$dir" PREFIX="$1" "$2" "$3"
done < <(find test/* -type d -print0)
