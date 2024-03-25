//
// Created by nogel on 25/03/2024.
//

#ifndef PROJET_LANGAGE_C_COLUMN_H
#define PROJET_LANGAGE_C_COLUMN_H


typedef int Data;

typedef struct {
    char* title;
    int physicalSize;
    int logicalSize;
    Data* values;
} Column;

void insertValue(Column *column, Data value);
Column *createColumn(char* title);
#endif //PROJET_LANGAGE_C_COLUMN_H
