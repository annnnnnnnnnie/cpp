cmake --build build
cd build && ctest || ctest --rerun-failed --output-on-failure