
#include <iostream>
#include "SortQuestion.h"
#include "LinkListQuestion.h"

using namespace std;

int main()
{
	int input = 0;
	const enum QUESTIONS { SORT_QUESTION = 0, LINKED_LIST = 1 };

	SortQuestion sortQuestion;
	LinkListQuestion linkListQuestion;
	
	while (input < 2) {
		cout << "Hello, welcome to Assignment 2 for Algorithms and Data Structures." << endl;
		cout << "Please select the Program you would like to run" << endl;
		cout << "Press 0. to run question 1, the sorting algorithm" << endl;
		cout << "Press 1. to run question 2, the linked list" << endl;

		cin >> input;
		if (input == SORT_QUESTION) {
			sortQuestion.start_sort();
		}
		if (input == LINKED_LIST) {
			linkListQuestion.start_linked_list();
		}
	}
	cout << "please enter valid input" << endl;
	return 0;
}
