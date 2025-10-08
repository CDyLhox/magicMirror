cmake_minimum_required(VERSION 3.16)
project(magicMirror)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(magicMirror)

target_sources(magicMirror PRIVATE
    render.cpp
    saveAudio.cpp
    readAudio.cpp
    global.cpp
    chooseFile.cpp
    audioFolderInit.cpp
)

# ✅ Ensure proper compile features
target_compile_features(magicMirror PRIVATE cxx_std_20)

