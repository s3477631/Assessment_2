#include "Sort.h"
#include <sstream>
#include <iostream>

using namespace std;

int* Sort::strip_numbers(string rawDataElements, int numberElements) {
    std::stringstream ss(rawDataElements);
    int* dataElements = new int[numberElements];
    int lineCount = 0;

    for (int i; ss >> i;) {
        dataElements[lineCount] = i;
        if (ss.peek() == ' ') {
            ss.ignore();
        }
        lineCount++;
    }
    if (lineCount != numberElements) {
        alert.errorMessage("more elements were declared, than elements in the array. Please fix this up, before continuing.");
        delete[] dataElements;
        return {};
    }
    else {
        return dataElements;
    }
    delete[] dataElements;
    return {};
}

int* Sort::merge_sort(int array[], int const begin, int const end)
{
    if (begin >= end) {
        return {}; // Returns recursivly
    }
    auto mid = begin + (end - begin) / 2;
    merge_sort(array, begin, mid);
    merge_sort(array, mid + 1, end);
    return merge(array, begin, mid, end);
}

int* Sort::merge(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto* leftArray = new int[subArrayOne],
        * rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne++];
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo++];
        indexOfMergedArray++;
    }

    delete[] leftArray;
    delete[] rightArray;

    return array;
}

void Sort::swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// partition the array using last element as pivot
int Sort::partition(int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot 
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        //if current element is smaller than pivot, increment the low element
        //swap elements at i and j
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int* Sort::quick_sort(int array[], int const begin, int const end) {
        if (begin < end)
        {
            /* pi is partitioning index, arr[p] is now
               at right place */
            int pi = partition(array, begin, end);
            // Separately sort elements before
            // partition and after partition
            quick_sort(array, begin, pi - 1);
            quick_sort(array, pi + 1, end);
        }
        return array;
}


int* Sort::reverse_array(int array[], int size) {
    int* reversedArray = new int[size];
    int lineCount = 0;
    for (int i = size; i > -1; i--) {
        reversedArray[lineCount] = array[i];
        lineCount++;
    }
    return reversedArray;
}