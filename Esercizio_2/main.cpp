#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include "SortingAlgorithm.hpp"

using namespace std;
using namespace SortLibrary;

int main(int argc, char* argv[])
{

    if (argc < 2)
    {
        cout << "Enter a vector size as a Command line argument" << endl;
        return 1;
    }

    std::stringstream ss(argv[1]);
    int vector_size;
    ss >> vector_size;

    vector<int> randomvec = RandomVector(vector_size);

    clock_t start_time_BS = clock();
    SortLibrary::BubbleSort(randomvec);
    clock_t end_time_BS = clock();
    double bubble_sort_time = static_cast<double>(end_time_BS - start_time_BS) / CLOCKS_PER_SEC; //time for BubbleSort

    clock_t start_time_MS = clock();
    SortLibrary::MergeSort(randomvec);
    clock_t end_time_MS = clock();
    double merge_sort_time = static_cast<double>(end_time_MS - start_time_MS) / CLOCKS_PER_SEC; //time for MergeSort


    cout << "Vector size: " << vector_size << endl;
    cout << "Time for Bubble Sort: " << bubble_sort_time << " seconds" << endl;
    cout << "Time for Merge Sort: " << merge_sort_time << " seconds" << endl;

    return 0;
}
