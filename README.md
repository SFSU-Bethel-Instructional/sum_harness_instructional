
# sum_harness_instructional code harness

This directory contains a benchmark harness for testing different implementations of
summing numbers.

A single high-level main() is present in the benchmark.cpp file, which has definitions of problem sizes and so forth. 

main() will make calls to two routines that must be provided by your code:
* setup(N, A) // where you initialize N values in A
* result = sum(N, A) // where you compute the sum of N values in A and return the answer

This harness will generate three different executables using the one benchmark.cpp containing main(), and then using sum_direct.cpp, sum_indirect.cpp, or sum_vector.cpp.

Your job is to:

* Add code for setup() and sum() in each of sum_direct.cpp, sum_indirect.cpp, and sum_vector.cpp
* Add instrumention code in benchmark.cpp to measure elapsed time for the call to the sum() routine.
Have a look at the [chrono_timer](https://github.com/SFSU-Bethel-Instructional/chrono_timer) code repo for an example of instrumentation code that measures
elapsed time.

You should not need to modify anything inside CMakeLists.txt.

# Build environment prerequisites

To build and run this code, you need to have the following software tools installed on your platform:

* C++ compiler
* cmake
* make

# Default build instructions:


    cd sum_harness_instructional     # contains the source files and CMakeLists.txt file  
    mkdir build  
    cd build  
    cmake ../           # cmake generates lots of output   
    make                # to build the programs  



# Adding your code

You will need to add code in three places:

* Inside benchmark.cpp: please add instrumentation code that will measure and report elapsed time consumed by the call to the sum() routine. Please refer to the [chrono_timer code](https://github.com/SFSU-Bethel-Instructional/chrono_timer) for an example of how to do this kind of time measurement.

* The setup() routine inside each of sum_direct.cpp, sum_indirect.cpp, and sum_vector.cpp. See the homework writeup for details on how to perform initialization for each of these different codes.

* The sum() routine inside each of sum_direct.cpp, sum_indirect.cpp, and sum_vector.cpp. See the homework writeup for details on how to perform the sum operation for each of these different codes.

# Running the codes

Once the codes are built, you should be able to just run each one from the command line from within your build directory:

    ./sum_direct  

or 

    ./sum_indirect  

or

    ./sum_vector  

When you run each code, it will iterate through the set of problem sizes predefined inside benchmark.cpp

The instrumentation code you added to benchmark.cpp should report the elapsed time for your sum() method's execution for each problem size.

# Building and running the codes on Perlmutter@NERSC

After [logging in to perlmutter at NERSC,](https://docs.nersc.gov/systems/perlmutter/), either pull the code directly from git or [transfer a copy from your local machine to NERSC](https://docs.nersc.gov/services/scp/).

Set up your environment to make use of the CPU nodes by typing in this command:

    module load cpu

Then follow the build instructions above.

Once you have built the codes, you may request interactive access to a Perlmutter CPU node by using this command:

    salloc --nodes 1 --qos interactive --time 00:30:00 --constraint cpu --account=m3930

Once you are on an interactive Perlmutter CPU node, run each of the codes using these commands from within your build directory:

    ./sum_direct
    ./sum_indirect
    ./sum_vector


# Using the Python scripts for plotting on Perlmutter@NERSC

Included in the code harness are two Python files that will load a 
csv text file and use matplotlib.pyplot to create a 3-variable chart.
Please modify these Python files as needed to update the axis labels, 
plot title, and so forth.

To run Python on Perlmutter, first do a:

    module load python

That command will make available to you a full conda environment that 
is preloaded with many of the commonly used Python packages. The default
version of Python as of the time of this writing is 3.11.6.
Once you've loaded the python module, you can see the set of 
installed packages using this command:

    conda list

When you run the provided plot\_3vars.py Perlmutter, it will produce some 
output to the console and will also attempt to display the plot on your
screen. 

In order for the display to actually appear on your screen you must use
the -Y argument with ssh when you login, e.g.:

    ssh -Y user@saul-p1.nersc.gov

There are two python scripts in the distro: plot\_3vars.py and
plot\_3vars\_savefig.py. The difference between them is that the
plot\_3vars\_savefig.py will in addition to trying to display
the plot to the screen also save an image file named *myplot.png*.

# Additional build options -- Compiler Optimization Level

As of the time of this writing (Oct 2023), most SFSU students will not need
the information about different build options unless otherwise
instructed.

By default, the CMakeLists.txt will do a "Release" build, which means there will be full compiler optimizations.

If need be, there are two methods for modifying the compiler optimization level.

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

 Then, after setting the CMAKE_CXX_FLAGS_RELEASE environment variable, clean your build directory, and rerun cmake and then make.


Option 2 (works but not preferred): uncomment one of the following two lines then run/rerun cmake:

For -O3: full optimization 
   set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
For -O0: no optimization in gcc/g++
   set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O0")

After modifying CMakeLists.txt, clean your build directory, and rerun cmake and then make.


# EOF
