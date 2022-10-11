# copyright (C) 2022, E. Wes Bethel

cmake_minimum_required( VERSION 3.5)

project (sum_harness_instructional LANGUAGES CXX)

set(CMAKE_BUILD_TYPE "Release")
#set(CMAKE_CXX_FLAGS "-Wall")  # uncomment this line to turn on compiler warnings

# info for setting the compiler optimization level

# option 1 (best approach): set the CMAKE_CXX_FLAGS_RELEASE environment variable then run cmake

# for full optimization:
# bash users:
# % export CMAKE_CXX_FLAGS_RELEASE="-O3"
# csh users:
# % setenv CMAKE_CXX_FLAGS_RELEASE "-O3"

# for no optimization:
# bash users:
# % export CMAKE_CXX_FLAGS_RELEASE="-O0"
# csh users:
# % setenv CMAKE_CXX_FLAGS_RELEASE "-O0"


# option 2 (works but not preferred): uncomment one of the following two lines then run/rerun cmake:

# -O3 is full optimization in gcc/g++
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
# -O0 is no optimization in gcc/g++
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O0")


#
#  start of cmake rules: you shouldn't need to modify anything below here

# common library target for benchmarking
add_library(benchmark OBJECT benchmark.cpp)
target_compile_features(benchmark PRIVATE cxx_std_11)

add_executable (sum_direct sum_direct.cpp)
target_link_libraries(sum_direct PRIVATE benchmark)
target_compile_features(sum_direct PRIVATE cxx_std_11)
target_compile_options(sum_direct PRIVATE -Wall -pedantic -march=native)
#set(BENCHMARK "direct")
#configure_file(job.in job-${BENCHMARK})

add_executable (sum_vector sum_vector.cpp)
target_link_libraries(sum_vector PRIVATE benchmark)
target_compile_features(sum_vector PRIVATE cxx_std_11)
target_compile_options(sum_vector PRIVATE -Wall -pedantic -march=native)

add_executable (sum_indirect sum_indirect.cpp)
target_link_libraries(sum_indirect PRIVATE benchmark)
target_compile_features(sum_indirect PRIVATE cxx_std_11)
target_compile_options(sum_indirect PRIVATE -Wall -pedantic -march=native)

# EOF
