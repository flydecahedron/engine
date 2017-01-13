mkdir build;
cd build;
cmake .. -GNinja -DCMAKE_CONFIGURATION_TYPES="Debug;Release" -DCMAKE_INSTALL_PREFIX=..;
ninja install;
