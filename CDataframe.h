#include "column.h"

#ifndef CDATAFRAME_H
#define CDATAFRAME_H

typedef struct {
	Column* col;
	CDLink* next;
	int len;
} CDLink;

typedef CDLink* CDataframe;

CDataframe* new_cdataframe();
void set_value(int col, int line, Data x);


#endif