
# sum_harness_instructional code harness

This directory contains a benchmark harness for testing different implementations of
summing numbers.

A single high-level main() is present in the benchmark.cpp file, which has definitions of proble3m sizes and so forth. 

This main() will make calls to two routines that must be provided by your code:
* setup(N, A) // where you initialize N values in A
* result = sum(N, A) // where you compute the sum of N values in A and return the answer

This harness will generate three different executables using the one benchmark.cpp containing main(), and then using sum_direct.cpp, sum_indirect.cpp, or sum_vector.cpp.

Your job is to:

* Add code for setup() and sum() in each of sum_direct.cpp, sum_indirect.cpp, and sum_vector.cpp
* Add instrumention code in benchmark.cpp to measure elapsed time for the call to the sum() routine

You should not need to modify anything inside CMakeLists.txt.

# Default build instructions:


% cd sum_harness_instructional     # contains the source files and CMakeLists.txt file

% mkdir build

% cd build

% cmake ../           # cmake generates lots of output

% make                # to build the programs

# Additional build options -- Compiler Optimization Level

By default, the CMakeLists.txt will do a "Release" build, which means there will be full compiler optimizations.

There are two methods for modifying the compiler optimization level.

Option 1 (best approach): set the CMAKE_CXX_FLAGS_RELEASE environment variable then run cmake

For full optimization:  
 bash users:  
 % export CMAKE_CXX_FLAGS_RELEASE="-O3"  
 csh users:  
 % setenv CMAKE_CXX_FLAGS_RELEASE "-O3"  

For no optimization:  
 bash users:  
 % export CMAKE_CXX_FLAGS_RELEASE="-O0"  
 csh users:  
 % setenv CMAKE_CXX_FLAGS_RELEASE "-O0"  


Option 2 (works but not preferred): uncomment one of the following two lines then run/rerun cmake:

For -O3: full optimization 
   set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
For -O0: no optimization in gcc/g++
   set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O0")

Note: if you modify CMakeLists.txt, you will need to rerun cmake and then rerun make. If you need to rerun cmake, it is best to delete everything in the build directory and start from scratch (\rm -rf).


# Adding your code

You will need to add code in three places:

* Inside benchmark.cpp: please add instrumentation code that will measure and report elapsed time consumed by the call to the sum() routine. Please refer to the chrono_timer code for an example of how to do this kind of time measurement.

* The setup() routine inside each of sum_direct.cpp, sum_indirect.cpp, and sum_vector.cpp. See the homework writeup for details on how to perform initialization for each of these different codes.

* The sum() routine inside each of sum_direct.cpp, sum_indirect.cpp, and sum_vector.cpp. See the homework writeup for details on how to perform the sum operation for each of these different codes.

# Running the codes

Once the codes are built, you should be able to just run each one from the command line:

% ./sum_direct

or 

% ./sum_indirect

or

% ./sum_vector

When you run each code, it will iterate through the set of problem sizes predefined inside benchmark.cpp

# Building and running the codes on Cori@NERSC

Please refer to lecture slides for additional information about accessing Cori, building your code there, and running your code there.


# EOF
