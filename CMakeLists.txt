cmake_minimum_required(VERSION 3.5)
project(lwpb VERSION 0.0.1)

add_library(lwpb STATIC
  lwpb/core/buf.c
  lwpb/core/decoder.c
  lwpb/core/encoder.c
  lwpb/core/misc.c
  lwpb/rpc/direct.c
  lwpb/rpc/transport.c
  lwpb/utils/struct_decoder.c
  lwpb/utils/utils.c
)
target_include_directories(lwpb PUBLIC "${CMAKE_SOURCE_DIR}/include")
