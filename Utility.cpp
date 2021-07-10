// student no: A00030840
#include "Utility.h"
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

void Utility::writeToFile(string fileName, double time)
{
	ofstream myfile;
	myfile.open(fileName);
	myfile << time << endl;
	myfile.close();
}


void Utility::writeToLastLine(string fileName, int* content, int size) {
	std::fstream file(fileName, std::ios::out | std::ios::app);
		for (int count = 0; count < size; count++) {
		file << content[count] << " ";
		}
}

void Utility::writeNewLine(string fileName, double time) {
	std::fstream file(fileName, std::ios::out | std::ios::app);
	file << time << endl;
	cout << time << endl;
}

int Utility::generateRandomNumber() {
	srand((unsigned)time(0));
	return 1 + (rand() % 9);
}