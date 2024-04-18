//
// Created by nogel on 25/03/2024.
//
#include "column.h"


Column *createColumn(char* title){
    Column* column = (Column*) malloc(sizeof(Column));
    column->title= (char*) malloc(sizeof(char)* (strlen(title)+1));
    strcpy(column->title, title);
    column->logicalSize =0;
    column->physicalSize = 0;
    column->values = NULL;
    return column;
}

void delete_column(Column** col) {
    free((*col)->values);
    free((*col)->title);
    free(*col);
}

int nb_equal_values(Column col, Data x)
{
    int occurr = 0;
    for (int i = 0; i < col.logicalSize; i++)
        if (col.values[i] == x)
            occurr++;
    return occurr;
}

int nb_lower_values(Column col, Data x)
{
    int occurr = 0;
    for (int i = 0; i < col.logicalSize; i++)
        if (col.values[i] < x)
            occurr++;
    return occurr;
}

int nb_higher_values(Column col, Data x)
{
    int occurr = 0;
    for (int i = 0; i < col.logicalSize; i++)
        if (col.values[i] > x)
            occurr++;
    return occurr;
}

void insertValue(Column *column, Data value){
    if (column->logicalSize == column->physicalSize){
        column->physicalSize += REALLOC_SIZE;
        column->values = (Data*) realloc(column->values, column->physicalSize * sizeof(Data));
    }
    column->values[column->logicalSize] = value;
    column->logicalSize+=1;
}

void print_col(Column* col){
    for(int i = 0; i<col->logicalSize; i++)
        printf("[%d] %d\n", i, col->values[i]);
}


int return_value_by_index(Column col, Data i){
    return col.values[i];
}


