//
// (C) 2022, E. Wes Bethel
// benchmark-* harness for running different versions of the sum study
//    over different problem sizes
//
// usage: no command line arguments
// set problem sizes, block sizes in the code below

#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
#include <string.h>


extern void setup(int64_t N, uint64_t A[]);
extern int64_t sum(int64_t N, uint64_t A[]);

/* The benchmarking program */
int main(int argc, char** argv) 
{
   std::cout << std::fixed << std::setprecision(2);

#define MAX_PROBLEM_SIZE 1 << 28  //  256M
   std::vector<int64_t> problem_sizes{ MAX_PROBLEM_SIZE >> 5, MAX_PROBLEM_SIZE >> 4, MAX_PROBLEM_SIZE >> 3, MAX_PROBLEM_SIZE >> 2, MAX_PROBLEM_SIZE >> 1, MAX_PROBLEM_SIZE};
   
   std::vector<uint64_t> A(MAX_PROBLEM_SIZE);

   int64_t t;
   int n_problems = problem_sizes.size();

   /* For each test size */
   for (int64_t n : problem_sizes) 
   {
      printf("Working on problem size N=%d \n", n);

      // invoke user code to set up the problem
      setup(n, &A[0]);

      auto start = std::chrono::steady_clock::now(); // start timer

      // invoke method to perform the sum
      t = sum(n, &A[0]);

      auto end = std::chrono::steady_clock::now(); // end timer

      // calculate elapsed time and print
      auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
      printf("Elapsed time: %lld ms\n", elapsed_time);

      printf(" Sum result = %lld \n",t);
   } // end loop over problem sizes
}
