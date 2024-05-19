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


enum enum_type
{
    NULLVAL = 1 , UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
};
typedef enum enum_type ENUM_TYPE;

union column_type{
    unsigned int uint_value;
    signed int int_value;
    char char_value;
    float float_value;
    double double_value;
    char* string_value;
    void* struct_value;
};
typedef union column_type COL_TYPE ;


struct column {
    char *title;
    unsigned int size; //logical size
    unsigned int max_size; //physical size
    ENUM_TYPE column_type;
    COL_TYPE **data; // array of pointers to stored data
    unsigned long long int *index; // array of integers
};
typedef struct column COLUMN;

void insertValue(Column *column, Data value);

Column* createColumn(char* title);

void delete_column(Column** col);

int nb_equal_values(Column col, Data x);
int nb_lower_values(Column col, Data x);
int nb_higher_values(Column col, Data x);

void print_col(Column* col);

int return_value_by_index(Column col, Data i);

#endif PROJET_LANGAGE_C_COLUMN_H
