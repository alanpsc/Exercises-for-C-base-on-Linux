#include <cstddef>
#include <iostream>
#include <cstring>
#include "point.h"

/* max length for transforming into string from point value */
//#define BUFSIZ 500		

using namespace std;  

struct POINT {
	int x;
	int y;
};

PPOINT PtCreat (int x, int y) {
	PPOINT t = new POINT;
	t->x = x;
	t->y = y;
	return t;
}

void PtDestroy (PPOINT & point) {
	if (point) {
		delete point;
		point = NULL;
	}
}

void PtGetValue (PPOINT point, int & x, int & y) {
	if (point) {
		x = point->x;
		y = point->y;
	}
}

void PtSetValue (PPOINT point, int x, int y) {
	if (point) {
		point->x = x;
		point->y = y;
	}				
}

bool PtCompare (PPOINT point1, PPOINT point2) {
	if (!point1 || !point2) {
		cout << "PtCompare: Illeage Parameter(s)." << endl;
		exit (1);								
	}
	return (point1->x == point2->x && point1->y == point2->y);
}

char * DuplicateString (const char * str) {
	unsigned int len = strlen (str);
	char * tmp = new char[len + 1];
	for (unsigned int i = 0; i < len; i ++) {
		tmp[i] = str[i];
	}
	tmp[len] = '\0';
	return tmp;
}

char * PtTransformIntoString (PPOINT point) {
	char buf[BUFSIZ];
	if (point) {
		sprintf (buf, "(%d, %d)", point->x, point->y);
		return DuplicateString (buf);
	}
	else {
		return NULL;
	}
	
}
