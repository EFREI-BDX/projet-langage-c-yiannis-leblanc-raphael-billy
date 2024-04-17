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