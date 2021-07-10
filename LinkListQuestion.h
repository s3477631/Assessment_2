#ifndef LINKEDLISTQUESTION_H
#define LINKEDLISTQUESTION_H

#include "Utility.h"
#include "List.h"
class LinkListQuestion
{
private:

	Utility utility;
	int extractedNumber = 0;
	void insert_start();
	void insert_end();
	void delete_start();
	void delete_end();

	List listInsertBeginning;
	List listInsertEnd;

public:
	void start_linked_list();
};

#endif