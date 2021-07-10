#include "ErrorHandler.h"
#include <iostream>

using namespace std;

void ErrorHandler::errorMessage(string message) {
		cout << message << endl;
		exit(1);
};

void ErrorHandler::infoMessage(string message) {
	cout << message << endl;
	exit(0);
}