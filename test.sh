#!/bin/bash

case $1 in
1)
	for exec in $(find build -type f -name *.exe); do wine $exec; done
	;;
*)
	for exec in $(find build -type f -name *.app); do $exec; done
	;;
esac
