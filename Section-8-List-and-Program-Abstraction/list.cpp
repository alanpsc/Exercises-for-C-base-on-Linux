#include <cstddef>
#include <iostream>
#include "point.h"

using namespace std;

//#define NDEBUG

struct NODE;
typedef struct NODE* PNODE;


struct NODE {
	PPOINT data;
	PNODE next;
};


struct LIST;
typedef struct LIST* PLIST;

struct LIST {
	int count;
	PNODE head;
	PNODE tail;
};

PLIST LICreat () {
	PLIST p = new LIST;
	p->count = 0;
	p->head = NULL;	
	p->tail = NULL;
	return p;
}

#ifndef NDEBUG
void LIGetValue (PLIST list, int & count, PNODE & head, PNODE & tail) {
	count = list->count;
	head = list->head;	
	tail = list->tail;	
}
#endif


void LIClear (PLIST list) {
	if (!list) {
		cout << "LIClear: Illegal Parameter." << endl;
		exit (1);
	}
	while (list->head) {
		PNODE tmp = list->head;
		list->head = tmp->next;
		PtDestroy (tmp->data);
		delete tmp;	
		list->count --;	
	}
	list->tail = NULL;
}

void LIDestroy (PLIST list) {
	if (list) {
		LIClear (list);
		delete list;
		list = NULL;
	}
}

void LIAppend (PLIST list, PPOINT point) {
	if (!list || !point) {
		cout << "LIAppend: Illegal Parameter(s)." << endl;
		exit (1);
	}
	
	PNODE tmp = new NODE;
	if (!list->head) {			// no node before appending this point
		list->head = tmp;
	}
	else {						// exist node(s) before appending this point
		list->tail->next = tmp;
	}
	list->tail = tmp;	
	tmp->data = point;	
	tmp->next = NULL;		
	list->count ++;
}

void LIInsert (PLIST list, PPOINT point, unsigned int pos) {
	if (!list || !point) {
		cout << "LIInsert: Illegal Parameter(s)." << endl;
		exit (1);
	}

	PNODE tmp = new NODE;
	tmp->data = point;
	list->count ++;	
	if (pos < list->count) {		// really insert into node(s)
		if (0 == pos) {				// insert into head node
			tmp->next = list->head;
			list->head = tmp;
		}
		else {						// insert between two nodes
			for (PNODE prev = list->head, unsigned i = 0; i < pos - 1; i ++) {
				prev = prev->next;				
			}
			tmp->next = prev->next;
			prev->next = tmp;
		}
	}
	else {							// append to tail node
		list->tail->next = tmp;		
		list->tail = tmp;
		tmp->next = NULL;			
	}
}
