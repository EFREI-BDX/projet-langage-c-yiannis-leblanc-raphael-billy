#include "CDataframe.h"

int in_cdata(CDataframe tab, Data x) {
    if (nb_equal_cdata(tab, x) > 0) {
        return 1;
    }
    else return 0;
}

int nb_ligne(CDataframe tab) {
    CDLink* maillon = tab;
    int max = 0;
    while (maillon != NULL) {
        if (maillon->col->logicalSize > max) {
            max = maillon->col->logicalSize;
        }
        maillon = maillon->next;
    }
    return max;
}


int nb_colonne(CDataframe tab) {
    int nb_col = 0;
    CDLink* current_link = tab;
    while (current_link != NULL) {
        nb_col++;
        current_link = current_link->next;
    }
    return nb_col;
}

int nb_equal_cdata(CDataframe tab, Data x) {
    int occurrence = 0;
    CDLink* maillon = tab;
    while (maillon != NULL) {
        occurrence += nb_equal_values(*(maillon->col), x);
        maillon = maillon->next;
    }
    return occurrence;
}

int nb_higher_cdata(CDataframe tab, Data x) {
    int compteur = 0;
    CDLink* maillon = tab;
    while (maillon != NULL) {
        compteur += nb_higher_values(*(maillon->col), x);
        maillon = maillon->next;
    }
    return compteur;
}

int nb_lower_cdata(CDataframe tab, Data x) {
    int compteur = 0;
    CDLink* maillon = tab;
    while (maillon != NULL) {
        compteur += nb_lower_values(*(maillon->col), x);
        maillon = maillon->next;
    }
    return compteur;
}

CDLink* get_cdlink(CDataframe tab, int col) {
    for (int i = 0; i < col; i++) {
        if (tab == NULL) return NULL;

        tab = tab->next;
    }
    return tab;
}