#!/bin/bash

function check_for_build
{
	if [[ ! -d "./build" ]]; then
		echo "build does not exist"
		exit 1
	fi
}

check_for_build
make -f makefile