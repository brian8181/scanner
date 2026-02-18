#!/bin/bash

pushd ./cmake
cmake -G 'Unix Makefiles' .
make
popd
