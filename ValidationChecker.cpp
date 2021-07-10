// student no: A00030840
#include "ValidationChecker.h"
#include <iostream>

using namespace std;

int ValidationChecker::boolean_checker(int value)
{
    if (value == 0) {
        return 0;
    }
    else if (value == 1) {
        return 1;
    }
    else {
        alert.errorMessage("isAscending or isWorstComplexity has been given a false value, please change to either 0 or 1");
    }
}
int ValidationChecker::number_elements_checker(int elements) {
        if (elements > 0) {
            return elements;
        }
        else if (elements == 0) {
            alert.infoMessage("There are no values to sort");
        }
        else if (elements < 0) {
            alert.errorMessage("cannot have a negative number of elements");
        }
}