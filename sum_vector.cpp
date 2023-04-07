#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>
#include <string.h>

void 
setup(int64_t N, uint64_t A[])
{
   printf(" inside sum_vector problem_setup, N=%lld \n", N);
   
   std::vector<uint64_t> v(A, A + N);
}

int64_t
sum(int64_t N, uint64_t A[])
{
   printf(" inside sum_vector perform_sum, N=%lld \n", N);

   std::vector<uint64_t> v(A, A + N);
   int64_t sum = std::accumulate(v.begin(), v.end(), 0);

   return sum;
}
