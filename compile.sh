#/bin/bash
# using west
west build -b blackpill_f401cc -p always
# using cmake and ninja
cmake -Bbuild -GNinja
ninja -Cbuild