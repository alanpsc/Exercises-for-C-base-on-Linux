#ifndef _POINT_H_
#define _POINT_H_

struct POINT;
typedef struct POINT * PPOINT;

PPOINT PtCreat (int x, int y);
void PtDestroy (PPOINT & point);
void PtGetValue (PPOINT point, int & x, int & y);
void PtSetValue (PPOINT point, int x, int y);
bool PtCompare (PPOINT point1, PPOINT point2);
char * PtTransformIntoString (PPOINT point);


#endif
