#include "CDataframe.h"

void add_line(CDataframe tab, int line) {
    while (tab != NULL) {
        if (line >= tab->col->logicalSize) {
            set_col_value(tab->col, line, NULL);
        }
        else {
            insertValue(tab->col, NULL);
            for (int i = line; i < (tab->col->logicalSize - 1); i++) {
                tab->col->values[i + 1] = tab->col->values[i];
            }
            set_col_value(tab->col, line, NULL);
        }
        tab = tab->next;
    }
}

void del_line(CDataframe tab, int line) {
    while (tab != NULL) {
        switch (tab->col->type) {
        case STRING:
            free(tab->col->values[line].string_value);
        case STRUCTURE:
            free(tab->col->values[line].struct_value);
        }
        if (line < tab->col->logicalSize) {
            for (int i = line; i < (tab->col->logicalSize - 1); i++) {
                tab->col->values[i] = tab->col->values[i + 1];
            }
            tab->col->logicalSize--;
        }
        tab = tab->next;
    }
}

void add_col_input(CDataframe* tab) {
    int col;
    do {
        printf("Saisir la position de la colonne ajoutée : ");
    } while (!scanf("%d", &col));
    char name[TITLE_INPUT_SIZE];
    do {
        printf("Saisir le nom de la colonne : ");
    } while (!scanf("%s", name));
    ENUM_TYPE type = NULLVAL;
    do {
        printf("Saisir le type de la colonne\n(entier non signé : 2, entier : 3, caractere : 4, float : 5, double : 6, chaine de caracteres : 7) : ");
    } while (!scanf("%d", type) || !(type >= UINT && type <= STRING));
    add_col(tab, col, name,type);
}


void add_col(CDataframe* tab, int col, char* name, ENUM_TYPE type) {
    if (col > nb_colonne(*tab)) {
        char* vide = { '\0' };
        ENUM_TYPE noType = NULLVAL;
        add_col(tab, (col - 1), vide,noType);
    }
    if (col > nb_colonne(*tab)) return;

    CDLink* new_link = (CDLink*)malloc(sizeof(CDLink));
    if (new_link == NULL) return;

    Column* new_col = createColumn(type, name);
    if (new_col == NULL) {
        free(new_link);
        return;
    }
    new_link->col = new_col;
    new_link->next = NULL;
    if (*tab == NULL) {
        *tab = new_link;
        return;
    }

    CDLink* last = *tab;
    for (int i = 0; i < col && last->next != NULL; i++) {
        last = last->next;
    }
    CDLink* temp = last->next;
    last->next = new_link;
    new_link->next = temp;
}

void del_col(CDataframe* tab, int col) {
    if (nb_colonne(*tab) > col) return;

    CDLink** previous = tab;
    for (int i = 0; i < (col - 1); i++) {
        if ((*previous)->next == NULL) return;

        previous = &(*previous)->next;
    }
    CDLink* temp = (*previous)->next;
    (*previous) = temp->next;
    delete_column(&temp->col);
    free(temp);
}