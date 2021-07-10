// student no: A00030840

#include <iostream>
#include <chrono>
#include <sstream>
#include<fstream>
#include "LinkListQuestion.h"
#include "List.h"


using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;


void LinkListQuestion::start_linked_list()
{
	string line;
	ifstream myfile("input-a1q2.txt");

	if (myfile.is_open())
	{
		while (getline(myfile, line)) {
			extractedNumber = stoi(line);
		}
	}

	myfile.close();
	insert_start();
	insert_end();
	delete_start();
	delete_end();
}

void LinkListQuestion::insert_start() {
	auto t1 = high_resolution_clock::now();
	for (int i = 0; i < extractedNumber; i++) {
		listInsertBeginning.insert_at_beginning(utility.generateRandomNumber());
	}
	auto t2 = high_resolution_clock::now();
	std::chrono::duration<double, std::milli> fp_ms = t2 - t1;
	utility.writeNewLine("output-a1q2.txt", fp_ms.count());
}

void LinkListQuestion::insert_end() {

	auto t1 = high_resolution_clock::now();
	for (int i = 0; i < extractedNumber; i++) {
		listInsertEnd.insert_at_end(utility.generateRandomNumber());
	}
	auto t2 = high_resolution_clock::now();
	std::chrono::duration<double, std::milli> fp_ms = t2 - t1;
	utility.writeNewLine("output-a1q2.txt", fp_ms.count());
}

void LinkListQuestion::delete_start() {
	auto t1 = high_resolution_clock::now();
	listInsertBeginning.delete_from_beginning();
	auto t2 = high_resolution_clock::now();
	std::chrono::duration<double, std::milli> fp_ms = t2 - t1;
	utility.writeNewLine("output-a1q2.txt", fp_ms.count());
}

void LinkListQuestion::delete_end() {
	auto t1 = high_resolution_clock::now();
	listInsertEnd.delete_from_end();
	auto t2 = high_resolution_clock::now();
	std::chrono::duration<double, std::milli> fp_ms = t2 - t1;
	utility.writeNewLine("output-a1q2.txt", fp_ms.count());
}


