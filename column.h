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

typedef struct {
    char* title;
    unsigned int physicalSize;
    unsigned int logicalSize;
    Data* values;
    ENUM_TYPE type;
    unsigned int* index;
} Column;

typedef enum {
    NULLVAL = 1, UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
} ENUM_TYPE;

typedef union {
    unsigned int uint_value;
    signed int int_value;
    char char_value;
    float float_value;
    double double_value;
    char* string_value;
    void* struct_value;
} Data;

void insertValue(Column *column, Data value);

Column* createColumn(ENUM_TYPE type, char* title);

void delete_column(Column** col);

int nb_equal_values(Column col, Data x);
int nb_lower_values(Column col, Data x);
int nb_higher_values(Column col, Data x);

void print_col(Column* col);

void set_col_value(Column* col,int index, Data value);

Data defaultValue(ENUM_TYPE type);

#endif PROJET_LANGAGE_C_COLUMN_H
