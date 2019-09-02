#!/bin/bash

cd "$(dirname $0)"

if ! test -e origin/; then
    ./refresh.sh
fi

cd origin/
make redox_w:olemartinorg:avrdude
mv redox_w_olemartinorg.hex ../
cd ..
