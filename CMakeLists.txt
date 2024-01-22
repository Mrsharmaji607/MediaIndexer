cmake_minimum_required(VERSION 3.10)
project(MediaScannerProject)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(media_app

MediaScanner.h
MediaExtractor.h
MediaDatabse.h
Songs.h
    main.cpp
    MediaScanner.cpp
    MediaExtractor.cpp
    MediaDatabse.cpp
    Songs.cpp

)

# Set include directories
target_include_directories(media_app PRIVATE include)
