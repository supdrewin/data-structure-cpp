#!/bin/bash

export LANG=en_US.UTF-8

clear

echo -e "\e[33;1m$(date) - Making ${PWD##*/} by $USER...\e[0;36m"

while read -rd '' dir; do
	make -C "$dir" PREFIX="$1" "$2" "$3"
done < <(find test/* -type d -print0)
