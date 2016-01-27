#include <iostream>
#include "list.h"
#include "point.h"

using namespace std;

int main () {
/*
	PLIST p = LICreat ();
	int count;
	PNODE head, tail;
	LIGetValue (p, count, head, tail);
	cout << count << " " << head << " " << tail << endl;
	
	PPOINT pt = PtCreat (12, 4);
	int a, b;
	PtGetValue (pt, a, b);
	cout << a << " " << b << endl;
	//PtDestroy (pt);
	//PPOINT pt2;
	//PtDestroy (pt2);
	if (pt) cout << "it's pt." << endl;
	
	PtSetValue (pt, 4, 10);
	int c, d;
	PtGetValue (pt, c, d);
	cout << c << " " << d << endl;
*/

/*
	PPOINT pt1 = PtCreat (2,7);
	//PPOINT pt2 = NULL;
	PPOINT pt2 = PtCreat (32,7);
	
	if ( PtCompare (pt1, pt2) ) {
		cout << "Same Postion Points." << endl;
	}
	else {
		cout << "No Same Postion Points." << endl;
	}
	
	
	char * ptstr = PtTransformIntoString (pt1);
	for (int i = 0; ptstr[i]; i ++) {
		cout << *(ptstr + i);
	}
*/

	PLIST list = LICreat ();
	PPOINT point = PtCreat (2, 4);
	LIAppend (list, point);
	PPOINT point2 = PtCreat (50,80);
	LIAppend (list, point2);
	int count;
	PNODE head, tail;	
	LIGetValue (list, count, head, tail);
	cout << "count: " << count << endl;
	int x, y;
	PtGetValue (point2, x, y);
	cout << "x: " << x << endl;
	
//	cout << "x: " << lt->count << endl;




	
	
	
/*	
	PtDestroy (pt1);
	PtDestroy (pt2);
	PtCompare (pt1, pt2);
*/	
	
	
	
	
	
	
	
	return 0;
}
