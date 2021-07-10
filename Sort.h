#ifndef SORT_H
#define SORT_H


#include <iostream>
#include "ErrorHandler.h"
#include <vector>

using namespace std;
class Sort
{
private:
	int* merge(int array[], int const left, int const mid, int const right);
	int partition(int array[], int begin, int end);
	void swap(int* a, int* b);
	ErrorHandler alert;
public:
	int* strip_numbers(string rawDataElements, int numberElements);
	int* merge_sort(int array[], int const begin, int const end);
	int* quick_sort(int array[], int const begin, int const end);
	int* reverse_array(int array[], int size);
};

#endif