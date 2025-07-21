cmake -S . -B build
cmake --build build
if [ $? == 0 ]; then
    ./build/KARTGAME
fi
