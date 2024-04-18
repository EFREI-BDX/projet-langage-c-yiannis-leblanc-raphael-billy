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





int nb_ligne(CDataframe);
int nb_colonne(CDataframe);
int nb_equal_values(CDataframe , Data x);
void nb_higher_values(CDataframe , Data x);
void nb_lower_values(CDataframe , Data x);
void nom_colonne(CDataframe);

#endif