//
// Created by nogel on 25/03/2024.
//
#include "column.h"


Column *createColumn(ENUM_TYPE type, char* title){
    Column* column = (Column*) malloc(sizeof(Column));
    if (column == NULL) return NULL;

    column->title = (char*)malloc(sizeof(char) * (strlen(title) + 1));
    if (column->title == NULL) {
        free(column);
        return NULL;
    }

    strcpy(column->title, title);
    column->logicalSize = 0;
    column->physicalSize = 0;
    column->values = NULL;
    column->type = type;
    column->index = NULL;
    return column;
}

void delete_column(Column** col) {
    if (*col == NULL) return;

    free((*col)->values);
    free((*col)->title);
    free((*col)->index);
    free(*col);
}

int nb_equal_values(Column col, Data x) {
    switch (col.type) {
    case UINT:
        int occurr = 0;
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].unit_value == x.uint_value)
                occurr++;
        return occurr;

    case INT:
        int occurr = 0;
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].int_value == x.int_value)
                occurr++;
        return occurr;

    case CHAR:
        int occurr = 0;
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].char_value == x.char_value)
                occurr++;
        return occurr;

    case FLOAT:
        int occurr = 0;
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].float_value == x.float_value)
                occurr++;
        return occurr;

    case DOUBLE:
        int occurr = 0;
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].double_value == x.double_value)
                occurr++;
        return occurr;

    case STRING:
        int occurr = 0;
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].string_value == x.string_value)
                occurr++;
        return occurr;

    case STRUCTURE:
        int occurr = 0;
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].struct_value == x.struct_value)
                occurr++;
        return occurr;

    default:
        break;
    }

    int occurr = 0;
    for (int i = 0; i < col.logicalSize; i++)
        if (col.values[i] == x)
            occurr++;
    return occurr;
}

int nb_lower_values(Column col, Data x) {
    int occurr = 0;
    switch (col.type) {
    case UINT:
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].uint_value < x.uint_value)
                occurr++;
        break;
    case INT:
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].int_value < x.int_value)
                occurr++;
        break;
    case CHAR:
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].char_value < x.char_value)
                occurr++;
        break;
    case FLOAT:
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].float_value < x.float_value)
                occurr++;
        break;
    case DOUBLE:
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].double_value < x.double_value)
                occurr++;
        break;
    case STRING:
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].string_value < x.string_value)
                occurr++;
        break;
    case STRUCTURE:
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].struct_value < x.struct_value)
                occurr++;
        break;
    }
    return occurr;
}

int nb_higher_values(Column col, Data x) {
    int occurr = 0;
    switch (col.type) {
    case UINT:
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].uint_value > x.uint_value)
                occurr++;
        break;
    case INT:
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].int_value > x.int_value)
                occurr++;
        break;
    case CHAR:
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].char_value > x.char_value)
                occurr++;
        break;
    case FLOAT:
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].float_value > x.float_value)
                occurr++;
        break;
    case DOUBLE:
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].double_value > x.double_value)
                occurr++;
        break;
    case STRING:
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].string_value > x.string_value)
                occurr++;
        break;
    case STRUCTURE:
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].struct_value > x.struct_value)
                occurr++;
        break;
    }
    
    
    return occurr;
}

void insertValue(Column *column, Data value){
    if (column->logicalSize == column->physicalSize) {
        Column* newValues = (Data*)realloc(column->values, column->physicalSize + REALLOC_SIZE * sizeof(Data));
        if (newValues == NULL) return;

        column->values = newValues;
        column->physicalSize += REALLOC_SIZE;
    }
    switch (column->type) {
    case UINT:
        column->values[column->logicalSize].uint_value = value.uint_value;
        break;
    case INT:
        column->values[column->logicalSize].int_value = value.int_value;
        break;
    case CHAR:
        column->values[column->logicalSize].char_value = value.char_value;
        break;
    case FLOAT:
        column->values[column->logicalSize].float_value = value.float_value;
        break;
    case DOUBLE:
        column->values[column->logicalSize].float_value = value.float_value;
        break;
    case STRING:
        column->values[column->logicalSize].string_value = value.string_value;
        break;
    case STRUCTURE:
        column->values[column->logicalSize].string_value = value.struct_value;
        break;
    }
    column->logicalSize+=1;
}

void print_col(Column* col) {
    switch (col->type) {
    case UINT:
        for (int i = 0; i < col->logicalSize; i++)
            printf("[%d] %d\n", i, col->values[i].uint_value);
        break;
    case INT:
        for (int i = 0; i < col->logicalSize; i++)
            printf("[%d] %d\n", i, col->values[i].int_value);
        break;
    case CHAR:
        for (int i = 0; i < col->logicalSize; i++)
            printf("[%d] %c\n", i, col->values[i].char_value);
        break;
    case FLOAT:
        for (int i = 0; i < col->logicalSize; i++)
            printf("[%d] %f\n", i, col->values[i].float_value);
        break;
    case DOUBLE:
        for (int i = 0; i < col->logicalSize; i++)
            printf("[%d] %lf\n", i, col->values[i].double_value);
        break;
    case STRING:
        for (int i = 0; i < col->logicalSize; i++)
            printf("[%d] %s\n", i, col->values[i].string_value);
        break;
    }
}

void set_col_value(Column* col, int index, Data value) {
    if (col->logicalSize <= index) {
        Data defaultVal;
        switch (col->type) {
        case UINT:
            defaultVal.uint_value = 0;
            for (int i = (col->logicalSize - 1); i < index; i++) {
                insertValue(col, defaultVal);
            }
            break;
        case INT:
            defaultVal.int_value = 0;
            for (int i = (col->logicalSize - 1); i < index; i++) {
                insertValue(col, defaultVal);
            }
            break;
        case CHAR:
            defaultVal.char_value = '\0';
            for (int i = (col->logicalSize - 1); i < index; i++) {
                insertValue(col, defaultVal);
            }
            break;
        case FLOAT:
            defaultVal.float_value = 0.0;
            for (int i = (col->logicalSize - 1); i < index; i++) {
                insertValue(col, defaultVal);
            }
            break;
        case DOUBLE:
            defaultVal.double_value = 0.0;
            for (int i = (col->logicalSize - 1); i < index; i++) {
                insertValue(col, defaultVal);
            }
            break;
        case STRING:
            defaultVal.string_value = NULL;
            for (int i = (col->logicalSize - 1); i < index; i++) {
                insertValue(col, defaultVal);
            }
            break;
        case STRUCTURE:
            defaultVal.struct_value = NULL;
            for (int i = (col->logicalSize - 1); i < index; i++) {
                insertValue(col, defaultVal);
            }
            break;
        }
        
    }
    col->values[index] = value;
}

Data defaultValue(ENUM_TYPE type) {
    Data defaultVal;
    switch (type) {
    case UINT:
        defaultVal.uint_value = 0;
        break;
    case INT:
        defaultVal.int_value = 0;
        break;
    case CHAR:
        defaultVal.char_value = '\0';
        break;
    case FLOAT:
        defaultVal.float_value = 0.0;
        break;
    case DOUBLE:
        defaultVal.double_value = 0.0;
        break;
    case STRING:
        defaultVal.string_value = NULL;
        break;
    case STRUCTURE:
        defaultVal.struct_value = NULL;
        break;
    }
    return defaultVal;
}