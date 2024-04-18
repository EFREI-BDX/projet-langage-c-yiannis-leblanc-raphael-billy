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
void fill_blank_cdataframe(int nbCol, int nbLine);
void fill_cdataframe_input(int nbCol, int nbLine);
void set_value(int col, int line, Data x);
void print_cdataframe(CDataframe tab);
void print_lines(int line1, int line2);
void print_lines_input();
void print_col(int col1, int col2);
void add_line(CDataframe tab);
void del_line(CDataframe tab);
void add_col(CDataframe tab);
void rename_col(CDataframe tab, int col);
void is_in(CDataframe tab, Data x);


#endif