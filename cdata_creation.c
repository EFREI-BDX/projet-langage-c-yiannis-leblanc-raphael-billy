#include "CDataframe.h"

CDataframe new_cdataframe() {
    return NULL;
}

void fill_blank_cdata(CDataframe* tab, int nbCol, int nbLine) {
    if (*tab != NULL) {
        printf("Le CDataframe doit etre vide...\n");
        return;
    }
    char title[TITLE_INPUT_SIZE];
    Data value = 0;
    for (int i = 0; i < nbCol; i++) {
        do {
            printf("Saisir le nom de la colonne %d : ", i);
        } while (!scanf("%s", title));
        add_col(tab, i, title);
        for (int j = 0; j < nbLine; j++) {
            set_value(tab, i, j, value);
        }
    }
}

void fill_blank_cdata_input(CDataframe* tab) {
    int nbCol, nbLine;
    do {
        printf("Saisir les nombres de colonne et de ligne (a b) : ");
    } while (scanf("%d %d", &nbCol, &nbLine) < 2 || nbCol < 1 || nbLine < 0);
    fill_blank_cdata(tab, nbCol, nbLine);
}

void fill_cdata_input(CDataframe* tab) {
    int nbCol, nbLine;
    do {
        printf("Saisir les nombres de colonne et de ligne (a b) : ");
    } while (scanf("%d %d", &nbCol, &nbLine) < 2 || nbCol < 1 || nbLine < 0);
    fill_cdata(tab, nbCol, nbLine);
}

void fill_cdata(CDataframe* tab, int nbCol, int nbLine) {
    if (*tab != NULL) {
        printf("Le CDataframe doit etre vide...\n");
        return;
    }
    char title[TITLE_INPUT_SIZE];
    Data value;
    for (int i = 0; i < nbCol; i++) {
        do {
            printf("Saisir le nom de la colonne %d : ", i);
        } while (!scanf("%s", title));
        add_col(tab, i, title);
        for (int j = 0; j < nbLine; j++) {
            do {
                printf("Saisir la valeur en colonne %d ligne %d : ", i, j);
            } while (!scanf("%d", &value));
            set_value(tab, i, j, value);
        }
    }
}