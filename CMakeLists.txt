cmake_minimum_required(VERSION 3.17)
project(Compressors)

set(CMAKE_CXX_STANDARD 14)

add_executable(Compressors
        main.cpp
        src/other/Support.h
        src/other/Support.cpp
        src/other/Compressor.h
        src/other/Compressor.cpp
        src/compressors/AlphabetConstructor.h
        src/compressors/Huffman.h
        src/compressors/Huffman.cpp
        src/compressors/LZ77.h
        src/compressors/LZ77.cpp
        src/compressors/ShannonFano.h
        src/compressors/ShannonFano.cpp)