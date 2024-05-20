//
// Created by nogel on 25/03/2024.
//

#ifndef PROJET_LANGAGE_C_COLUMN_H
#define PROJET_LANGAGE_C_COLUMN_H
#define REALLOC_SIZE 256
#define TITLE_INPUT_SIZE 256
#define SIGNIFICANT_DIGIT 3
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Column{
    char* title;
    unsigned int physicalSize;
    unsigned int logicalSize;
    Data* values;
    ENUM_TYPE type;
    unsigned int* index;
};
typedef struct Column Column;

enum  ENUM_TYPE {
    NULLVAL = 1, UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
};
typedef enum ENUM_TYPE ENUM_TYPE;

union Data {
    unsigned int uint_value;
    signed int int_value;
    char char_value;
    float float_value;
    double double_value;
    char* string_value;
    void* struct_value;
};
typedef union Data Data;

int insertValue(Column *column, void* value);

Column* createColumn(ENUM_TYPE type, char* title);

void delete_column(Column** col);

int nb_equal_values(Column col, void* x);
int nb_lower_values(Column col, void* x);
int nb_higher_values(Column col, void* x);

void print_col(Column* col);

void set_col_value(Column* col,int index, void* value);

Data defaultValue(ENUM_TYPE type);

void get_col_val_str(char* str, Column col, int index);

int col_size(Column col);

#endif PROJET_LANGAGE_C_COLUMN_H
