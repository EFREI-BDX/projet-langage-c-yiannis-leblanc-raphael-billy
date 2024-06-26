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

void insertValue(Column *column, Data value);

Column* createColumn(char* title);

void delete_column(Column** col);

int nb_equal_values(Column col, Data x);
int nb_lower_values(Column col, Data x);
int nb_higher_values(Column col, Data x);

void print_col(Column* col);

int return_value_by_index(Column col, Data i);

#endif PROJET_LANGAGE_C_COLUMN_H
