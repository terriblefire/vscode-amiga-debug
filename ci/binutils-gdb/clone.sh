#!/bin/bash
set -euo pipefail
IFS=$'\n\t'
set -x

git clone --depth=1 https://github.com/BartmanAbyss/binutils-gdb.git
