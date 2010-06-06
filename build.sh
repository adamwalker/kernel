#!/bin/sh
export SOURCE_ROOT=`pwd`
make --directory=build --file=${SOURCE_ROOT}/Makefile $1

