#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include  <stdio.h>
#include  <stdlib.h>
#include <vector>
#include <chrono>
#include <iostream>

#include "SortQuestion.h"
#include "ErrorHandler.h"
#include "ValidationChecker.h"
#include "Sort.h"
#include "Utility.h"

using namespace std;
struct SortConfig {
    int isAscending = 0;
    int isWorstComplexity = 0;
    int numberElements = 0;
    string rawStringDataElements = "";
    int* unSortedElements;
    int* sortedElements;
    string outputFile = "output-a1q1.txt";
} sortConfig;

int* sortArray(Sort sort, SortConfig sortConfig) {
    if (sortConfig.isWorstComplexity == 0) {
        return sort.merge_sort(sortConfig.unSortedElements, 0, sortConfig.numberElements - 1);
    }
    else {
        return sort.quick_sort(sortConfig.unSortedElements, 0, sortConfig.numberElements - 1);
    }
}

int* reverseArray(Sort sort, SortConfig sortConfig) {
    if (sortConfig.isAscending) {
        return sortConfig.sortedElements;
    }
    else {
        return sort.reverse_array(sortConfig.sortedElements, sortConfig.numberElements - 1);
    }
}


void SortQuestion::start_sort() {

    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    string line;
    ifstream myfile("input-a1q1.txt");

    ValidationChecker check;
    Sort sort;
    Utility utility;

    const enum CONFIG_PARAMS { IS_ASCENDING = 0, IS_COMPLEX = 1, NUMB_ELEMENTS = 2, DATA_ELEMENTS = 3 };
    const int number_interations = 1000;

    int lineCount = 0;

    if (myfile.is_open())
    {
        while (getline(myfile, line)) {

            if (lineCount == IS_ASCENDING) {
                sortConfig.isAscending = check.boolean_checker(std::stoi(line));
            }
            if (lineCount == IS_COMPLEX) {
                sortConfig.isWorstComplexity = check.boolean_checker(std::stoi(line));
            }
            if (lineCount == NUMB_ELEMENTS) {
                sortConfig.numberElements = check.number_elements_checker(std::stoi(line));
            }
            if (lineCount == DATA_ELEMENTS) {
                sortConfig.unSortedElements = sort.strip_numbers(line, sortConfig.numberElements);
                auto t1 = high_resolution_clock::now();
                for (int i = 0; i < number_interations; i++) {
                    sortConfig.sortedElements = sortArray(sort, sortConfig);
                    sortConfig.sortedElements = reverseArray(sort, sortConfig);
                }
                auto t2 = high_resolution_clock::now();
                std::chrono::duration<double, std::milli> fp_ms = t2 - t1;
                utility.writeToFile(sortConfig.outputFile, fp_ms.count());
                utility.writeToLastLine(sortConfig.outputFile, sortConfig.sortedElements, sortConfig.numberElements);
            }
            lineCount++;
        }
    }
    myfile.close();
};