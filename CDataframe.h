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
void fill_blank_cdata(CDataframe tab, int nbCol, int nbLine);
void fill_cdata_input(CDataframe tab, int nbCol, int nbLine);
void set_value(CDataframe tab, int col, int line, Data x);
void print_cdata(CDataframe tab);
void print_cdata_lines(CDataframe tab, int line1, int line2);
void print_cdata_lines_input(CDataframe tab);
void print_cdata_col(CDataframe tab, int col1, int col2);
void add_line(CDataframe tab);
void del_line(CDataframe tab, int line);
void add_col(CDataframe tab);
void rename_cdata_col(CDataframe tab, int col);
void in_cdata(CDataframe tab, Data x);
int nb_ligne(CDataframe tab);
int nb_colonne(CDataframe tab);
int nb_equal_cdata(CDataframe tab, Data x);
void nb_higher_cdata(CDataframe tab, Data x);
void nb_lower_cdata(CDataframe tab, Data x);
void nom_colonne(CDataframe tab);

#endif