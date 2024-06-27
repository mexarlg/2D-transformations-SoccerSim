cmake_minimum_required(VERSION 3.12)
project(MyProject)

# Add your source files here
set(SOURCES 
    main.cpp
    2dTransformation.cpp)

# Add your executable target
add_executable(MyProject ${SOURCES})
# Add your include directories here
target_include_directories(MyProject PUBLIC include)

# Add your library dependencies here
target_link_libraries(MyProject PUBLIC my_library)