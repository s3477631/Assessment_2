#ifndef Utility_H
#define Utility_H
#include <chrono>


#include <iostream>

using namespace std;

class Utility
{
public:
	void writeToFile(string fileName, double time);
	void writeToLastLine(string fileName, int* content, int size);
	void writeNewLine(string fileName, double time);
	int generateRandomNumber();
};

#endif