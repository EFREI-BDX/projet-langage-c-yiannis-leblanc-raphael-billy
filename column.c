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

void insertValue(Column *column, Data value){
    if (column->logicalSize == column->physicalSize){
        column->physicalSize += REALLOC_SIZE;
        column->values = (Data*) realloc(column->values, column->physicalSize * sizeof(Data));
    }
    column->values[column->logicalSize] = value;
    column->logicalSize+=1;
}