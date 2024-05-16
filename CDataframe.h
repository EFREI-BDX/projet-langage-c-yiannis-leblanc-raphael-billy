#include "column.h"
#include <stdlib.h>

#ifndef CDATAFRAME_H
#define CDATAFRAME_H

struct CDLink {
	Column* col;
	struct CDLink* next;
};
typedef struct CDLink CDLink;
typedef CDLink* CDataframe;

CDataframe new_cdataframe();

CDLink* get_cdlink(CDataframe tab, int col);

void fill_blank_cdata_input(CDataframe* tab);
void fill_blank_cdata(CDataframe* tab, int nbCol, int nbLine);

void print_cdata_col_input(CDataframe tab);
void print_cdata_col(CDataframe tab, int col1, int col2);

void fill_cdata_input(CDataframe* tab);
void fill_cdata(CDataframe* tab, int nbCol, int nbLine);
//Raph
void set_value_input(CDataframe tab);//Raph
void set_value(CDataframe tab, int col, int line, Data x); //Raph

void print_cdata_lines_input(CDataframe tab);//Raph
void print_cdata_lines(CDataframe tab, int line1, int line2);

void print_cdata(CDataframe tab);//Raph *s'appuyer sur les fct print_cdata_col() et nb_colonne()*

void print_col_names(CDataframe tab);

void add_line(CDataframe tab, int line);
void del_line(CDataframe tab, int line);
void add_col(CDataframe* tab, int col);
void del_col(CDataframe* tab, int col);
// Raph
void rename_cdata_col_input(CDataframe tab);
void rename_cdata_col(CDataframe tab, int col, char* name);

int in_cdata(CDataframe tab, Data x);
int nb_ligne(CDataframe tab);
int nb_colonne(CDataframe tab);
int nb_equal_cdata(CDataframe tab, Data x);
int nb_higher_cdata(CDataframe tab, Data x);
int nb_lower_cdata(CDataframe tab, Data x);

#endif