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

int nb_equal_values(Column col, void* x) {
    int occurr = 0;
    switch (col.type) {
    case UINT:
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].uint_value == *((unsigned int*)x))
                occurr++;
        return occurr;

    case INT:
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].int_value == *((int*)x))
                occurr++;
        return occurr;

    case CHAR:
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].char_value == *((char*)x))
                occurr++;
        return occurr;

    case FLOAT:
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].float_value == *((float*)x))
                occurr++;
        return occurr;

    case DOUBLE:
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].double_value == *((double*)x))
                occurr++;
        return occurr;

    case STRING:
        for (int i = 0; i < col.logicalSize; i++)
            if (!strcmp(col.values[i].string_value, ((char*)x)))
                occurr++;
        return occurr;

    case STRUCTURE:
        printf("Le teste pour le type STRUCTURE est impossible...\n");
        return occurr;
        break;

    default:
        break;
    }
    return occurr;
}

int nb_lower_values(Column col, void* x) {
    int occurr = 0;
    switch (col.type) {
    case UINT:
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].uint_value < *((unsigned int*)x))
                occurr++;
        return occurr;

    case INT:
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].int_value < *((int*)x))
                occurr++;
        return occurr;

    case CHAR:
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].char_value > *((char*)x))
                occurr++;
        return occurr;

    case FLOAT:
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].float_value < *((float*)x))
                occurr++;
        return occurr;

    case DOUBLE:
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].double_value < *((double*)x))
                occurr++;
        return occurr;

    case STRING:
        for (int i = 0; i < col.logicalSize; i++)
            if (strcmp(col.values[i].string_value, ((char*)x)) > 0)
                occurr++;
        return occurr;

    case STRUCTURE:
        printf("Le teste pour le type STRUCTURE est impossible...\n");
        return occurr;
        break;

    default:
        break;
    }
    return occurr;
}

int nb_higher_values(Column col, void* x) {
    int occurr = 0;
    switch (col.type) {
    case UINT:
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].uint_value > *((unsigned int*)x))
                occurr++;
        return occurr;

    case INT:
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].int_value > *((int*)x))
                occurr++;
        return occurr;

    case CHAR:
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].char_value < *((char*)x))
                occurr++;
        return occurr;

    case FLOAT:
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].float_value > *((float*)x))
                occurr++;
        return occurr;

    case DOUBLE:
        for (int i = 0; i < col.logicalSize; i++)
            if (col.values[i].double_value > *((double*)x))
                occurr++;
        return occurr;

    case STRING:
        for (int i = 0; i < col.logicalSize; i++)
            if (strcmp(col.values[i].string_value, ((char*)x)) < 0)
                occurr++;
        return occurr;

    case STRUCTURE:
        printf("Le teste pour le type STRUCTURE est impossible...\n");
        return occurr;
        break;

    default:
        break;
    }
    return occurr;
}

int insertValue(Column *column, void* value){
    if (column->logicalSize == column->physicalSize) {
        Column* newValues = (Data*)realloc(column->values, column->physicalSize + REALLOC_SIZE * sizeof(Data));
        if (newValues == NULL) return 0;

        column->values = newValues;
        column->physicalSize += REALLOC_SIZE;
    }
    set_col_value(column, column->logicalSize, value);
    column->logicalSize += 1;
    return 1;
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

void set_col_value(Column* col, int index, void* value) {
    switch (col->type) {
        case UINT:
            if (col->logicalSize <= index) {
                unsigned int defaultVal = 0;
                for (int i = (col->logicalSize - 1); i < index; i++) {
                    insertValue(col, (void*)&defaultVal);
                }
            }
            col->values[index].uint_value = *((unsigned int*)value);
            break;
        case INT:
            if (col->logicalSize <= index) {
                int defaultVal = 0;
                for (int i = (col->logicalSize - 1); i < index; i++) {
                    insertValue(col, (void*) &defaultVal);
                }
            }
            col->values[index].int_value = *((int*)value);
            break;
        case CHAR:
            if (col->logicalSize <= index) {
            char defaultVal = '\0';
            for (int i = (col->logicalSize - 1); i < index; i++) {
                insertValue(col, (void*) & defaultVal);
            }
        }
            col->values[index].char_value = *((char*)value);
            break;
        case FLOAT:
            if (col->logicalSize <= index) {
                float defaultVal = 0.0;
                for (int i = (col->logicalSize - 1); i < index; i++) {
                    insertValue(col, (void*) &defaultVal);
                }
            }
            col->values[index].float_value = *((float*)value);
            break;
        case DOUBLE:
            if (col->logicalSize <= index) {
                double defaultVal = 0.0;
                for (int i = (col->logicalSize - 1); i < index; i++) {
                    insertValue(col, (void*)&defaultVal);
                }
            }
            col->values[index].double_value = *((double*)value);
            break;
        case STRING:
            if (col->logicalSize <= index) {
                char* defaultVal = NULL;
                for (int i = (col->logicalSize - 1); i < index; i++) {
                    insertValue(col, (void*)defaultVal);
                }
            }
            col->values[index].string_value = (char*)value;
            break;
        case STRUCTURE:
            if (col->logicalSize <= index) {
                void* defaultVal = NULL;
                for (int i = (col->logicalSize - 1); i < index; i++) {
                    insertValue(col, defaultVal);
                }
            }
            col->values[index].struct_value = ((void*)value);
            break;
        }
}

Data defaultValue(ENUM_TYPE type) {
    Data defaultVal = { .int_value = 0 };
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
    case NULLVAL:
        defaultVal.int_value = 0;
    }
    return defaultVal;
}

void get_col_val_str(char* str, Column col, int index) {
    if (col.logicalSize > index) {
        switch (col.type) {
        case UINT:
            sprintf(str, "%d", col.values[index].uint_value);
            break;
        case INT:
            sprintf(str, "%d", col.values[index].int_value);
            break;
        case CHAR:
            sprintf(str, "%c", col.values[index].char_value);
            break;
        case FLOAT:
            sprintf(str, "%f", col.values[index].float_value);
            break;
        case DOUBLE:
            sprintf(str, "%lf", col.values[index].double_value);
            break;
        case STRING:
            sprintf(str, "%s", col.values[index].string_value);
            break;
        case STRUCTURE:
            strcpy(str, "[Structure]");
            break;
        case NULLVAL:
            strcpy(str, "[Type a renseigner]");
            break;
        default:
            strcpy(str, "[Type inconnu]");
            break;
        }
    }
    else {
        char vide[] = { '\0' };
        strcpy(str, vide);
    }
}

int col_size(Column col) {
    return col.logicalSize;
}
