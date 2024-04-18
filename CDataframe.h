#include "column.h"

#ifndef CDATAFRAME_H
#define CDATAFRAME_H

typedef struct {
	Column* col;
	CDLink* next;
} CDLink;

typedef CDLink* CDataframe;

#endif