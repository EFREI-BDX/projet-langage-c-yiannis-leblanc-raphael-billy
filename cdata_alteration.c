#include "CDataframe.h"

void add_line(CDataframe tab, int line) {
    while (tab != NULL) {
        if (line >= tab->col->logicalSize) {
            for (int i = (tab->col->logicalSize - 1); i < line; i++) {
                insertValue(tab->col, 0);
            }
        }
        else {
            insertValue(tab->col, 0);
            for (int i = line; i < (tab->col->logicalSize - 1); i++) {
                tab->col->values[i + 1] = tab->col->values[i];
            }
            tab->col->values[line] = 0;
        }
        tab = tab->next;
    }
}

void del_line(CDataframe tab, int line) {
    while (tab != NULL) {
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
    add_col(tab, col, name);
}


void add_col(CDataframe* tab, int col, char* name) {
    if (col > nb_colonne(*tab)) {
        char vide[TITLE_INPUT_SIZE] = {'\0'};
        add_col(tab, (col - 1), vide);
    }
    if (col > nb_colonne(*tab)) return;

    CDLink* new_link = (CDLink*)malloc(sizeof(CDLink));
    if (new_link == NULL) return;

    Column* new_col = createColumn(name);
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