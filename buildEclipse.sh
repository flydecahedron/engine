cd ../;
mkdir eclipse-build;
cd eclipse-build;
cmake ../engine -G"Eclipse CDT4 - Unix Makefiles" -D_ECLIPSE_VERSION=4.6.2 -DCMAKE_BUILD_TYPE=Debug -DCMAKE_ECLIPSE_GENERATE_SOURCE_PROJECT=TRUE -DCMAKE_CXX_COMPILER_ARG1=-std=c++14;
