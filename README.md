lwpb - Lightweight Protocol Buffers

A lightweight implementation of the Google Protocol Buffers for C, with a simple streaming interface for encoding and decoding. The library is designed to be used for embedded devices.

This is some modern cmake tooling wrapped around [the original](https://code.google.com/archive/p/lwpb/).

```
# configure
cmake -B build


# build
cmake --build build
```

You can use it in your cmake project, easily. Add [Findlwpb](Findlwpb.cmake) to your project, and use it, like this:

```cmake
# look in a specific dir for your Findlwpb.cmake file
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(lwpb)
```

Then you can link to it, like this:

```cmake
add_executable(yourthing yourthing.c)
target_link_libraries(yourthing lwpb)
```