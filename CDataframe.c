#include "CDataframe.h"

CDataframe* new_cdataframe() {
	return NULL;
}

void fill_blank_cdata(CDataframe tab, int nbCol, int nbLine) {
}

void print_cdata_col_input(CDataframe tab) {
}

void fill_cdata_input(CDataframe tab, int nbCol, int nbLine) {
}

void set_value_input(CDataframe tab) {
}

void print_cdata_lines_input(CDataframe tab) {
}

void set_value(CDataframe tab, int col, int line, Data x) {
}

void print_cdata(CDataframe tab) {
}

void print_cdata_lines(CDataframe tab, int line1, int line2) {
	if (tab == NULL) return;

	CDLink* sub_tab;
	for (int j = line1 ; j<=line2;j++){
		sub_tab = tab;
		do {
			if (j < sub_tab->col->logicalSize) {
				printf("%d", sub_tab->col->values[j]);
			}
			printf("\t");
			sub_tab = sub_tab->next;
		} while (sub_tab->next != NULL);
		printf("\n");
	}
}

void print_cdata_col(CDataframe tab, int col1, int col2) {
}

void print_col_names(CDataframe tab) {
}

void add_line(CDataframe* tab) {
}

void del_line(CDataframe* tab, int line) {
}

void add_col(CDataframe* tab) {
}

void del_col(CDataframe* tab, int line) {
}

void rename_cdata_col(CDataframe tab, int col) {
}

int in_cdata(CDataframe tab, Data x) {
	return 0;
}

int nb_ligne(CDataframe tab) {
	return 0;
}

int nb_colonne(CDataframe tab) {
	return 0;
}

int nb_equal_cdata(CDataframe tab, Data x) {
	return 0;
}

int nb_higher_cdata(CDataframe tab, Data x) {
	return 0;
}

int nb_lower_cdata(CDataframe tab, Data x) {
	return 0;
}
