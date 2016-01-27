#ifndef _LISH_H_
#define _LISH_H_

#include "point.h"

//#define NDEBUG

struct NODE;
typedef struct NODE * PNODE;

struct LIST;
typedef struct LIST * PLIST;

#ifndef NDEBUG
void LIGetValue (PLIST list, int & count, PNODE & head, PNODE & tail);
#endif

PLIST LICreat ();
void LIDestroy (PLIST list);
void LIAppend (PLIST list, PPOINT point);
void LIInsert (PLIST list, PPOINT point, unsigned int pos);

#endif



/*
#ifndef _DLL_H_
#define _DLL_H_

#if BUILDING_DLL
#define DLLIMPORT __declspec(dllexport)
#else
#define DLLIMPORT __declspec(dllimport)
#endif

class DLLIMPORT DllClass
{
	public:
		DllClass();
		virtual ~DllClass();
		void HelloWorld();
};

#endif
*/
