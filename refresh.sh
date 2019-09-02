#!/bin/bash

cd "$(dirname $0)"

if test -e origin/; then
    cd origin/
    git reset --hard
    git pull
    cd ..
else
    git clone https://github.com/mattdibi/qmk_firmware origin
fi

if ! test -e origin/keyboards/redox_w/keymaps/olemartinorg; then
    ln -s "$(pwd)/layout" origin/keyboards/redox_w/keymaps/olemartinorg
fi

cd origin/
for PATCHF in ../patches/*.patch; do
    patch -p1 -f < $PATCHF
done
cd ..
