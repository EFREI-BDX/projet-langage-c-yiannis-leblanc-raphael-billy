//
// Created by nogel on 25/03/2024.
//

#ifndef PROJET_LANGAGE_C_COLUMN_H
#define PROJET_LANGAGE_C_COLUMN_H
#define REALLOC_SIZE 256
#define TITLE_INPUT_SIZE 256
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef int Data;

typedef struct {
    char* title;
    int physicalSize;
    int logicalSize;
    Data* values;
} Column;

void insertValue(Column *column, void* value);

void set_col_value(Column* column, int index, void* val);

Column* createColumn(char* title);

void delete_column(Column** col);

int nb_equal_values(Column col, void* x);
int nb_lower_values(Column col, void* x);
int nb_higher_values(Column col, void* x);

int col_len(Column col);

void print_col(Column* col);

char* return_col_val_str(Column col, int i);

void* return_col_value(Column col, int i);

#endif PROJET_LANGAGE_C_COLUMN_H
