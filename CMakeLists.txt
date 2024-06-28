cmake_minimum_required(VERSION 3.12)
project(MyProject)

# Add your source files here
set(SOURCES 
    main.cpp
    2dTransformation.cpp)

# Add your executable target
add_executable(MyProject ${SOURCES})
