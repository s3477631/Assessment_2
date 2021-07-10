#ifndef VALIDATIONCHECKER_H
#define VALIDATIONCHECKER_H

#include <iostream>
#include "ErrorHandler.h"
#include <vector>

using namespace std;

class ValidationChecker
{
private: 
	ErrorHandler alert;
	public:
		int boolean_checker(int value);
		int number_elements_checker(int numberElements);
};

#endif

