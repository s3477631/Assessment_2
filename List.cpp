// student no: A00030840
#include "List.h"
#include <iostream>
using namespace std;
List::List()
{
	head = NULL;
	curr = NULL;
}

void List::insert_at_beginning(int addNode) {
	nodePointer n = new node;
	n->data = addNode;
	n->next = head;
	head = n;
}

void List::insert_at_end(int addNode) {
	nodePointer n = new node;
	n->data = addNode;
	n->next = NULL;
	if (head == NULL) {
		head = n;
	}
	else {
		nodePointer temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = n;
	}
}

void List::delete_from_beginning() {
	if (head == NULL) {
		return;
	}
	nodePointer n = head;
	head = head->next;
	delete n;
	return;
}

void List::delete_from_end() {
	if (head != NULL) {

		//1. if head in not null and next of head
		//   is null, release the head
		if (head->next == NULL) {
			head = NULL;
		}
		else {
			//2. Else, traverse to the second last 
			//   element of the list
			nodePointer n = head;
			while (n->next->next != NULL)
				n = n->next;

			//3. Change the next of the second 
			//   last node to null and delete the
			//   last node
			nodePointer lastPointer = n->next;
			n->next = NULL;
			free(lastPointer);
		}
	}
}