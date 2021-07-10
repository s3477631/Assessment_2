#ifndef LIST_H
#define LIST_H

class List
{
private:
	typedef struct node {
		int data;
		node* next;
	}*nodePointer;

	nodePointer head;
	nodePointer curr;
public:
	List();
	void insert_at_beginning(int value);
	void insert_at_end(int value);
	void delete_from_beginning();
	void delete_from_end();
};
#endif 


