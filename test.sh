#!/bin/bash

case $1 in
1)
	command -v wine &>/dev/null &&
		run=wine &&
		name="*.exe" ||
		name="*.app"
	;;
*)
	name="*.app"
	;;
esac

name=$(find build -name "$name")

for exec in $name; do
	$run "$exec" 2>/dev/null
	echo Press any key to continue
	read -rn 1
done
