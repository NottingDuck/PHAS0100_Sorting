#include <chrono>
#include "sorting.h"

#include <time.h>
#include <random>
#include <iostream>

typedef std::chrono::steady_clock myClock;

int main()
{
    std::srand(time(NULL)); //Randomize seed initialization

    int randSize = rand() % 999+1; // Generate a random number between 1 and 1000
    std::cout<<randSize<<std::endl;

    // create new vector
    std::vector<int> randVect;

    // fill element with random number
    for (int i=0;i<randSize;i++){
        int randNum = rand() %10000; // random num between 0 - 10000
        randVect.push_back(randNum);

        // std::cout<<randNum;
        // std::cout<<"\n";

    }

    // insertion_sort:
    std::chrono::time_point<myClock> t_start_I = myClock::now();

    insertion_sort(randVect);

    std::chrono::time_point<myClock> t_end_I = myClock::now();
    std::chrono::nanoseconds diff_I = t_end_I - t_start_I; 

    std::chrono::microseconds duration_I = std::chrono::duration_cast<std::chrono::microseconds>(diff_I);

    double seconds_I = double(duration_I.count())/1e6;


    // merge_sort:
    std::chrono::time_point<myClock> t_start_M = myClock::now();

    merge_sort(randVect);

    std::chrono::time_point<myClock> t_end_M = myClock::now();
    std::chrono::nanoseconds diff_M = t_end_M - t_start_M; 

    std::chrono::microseconds duration_M = std::chrono::duration_cast<std::chrono::microseconds>(diff_M);

    double seconds_M = double(duration_M.count())/1e6;

    std::cout<<seconds_I<<std::endl;
    std::cout<<seconds_M<<std::endl;

    return 0;
}