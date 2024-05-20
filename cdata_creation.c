#include "CDataframe.h"

CDataframe new_cdataframe() {
    return NULL;
}

void fill_blank_cdata(CDataframe* tab, int nbCol, int nbLine) { // Réparer la saisie des lignes
    if (*tab != NULL) {
        printf("Le CDataframe doit être vide...\n");
        return;
    }
    char title[TITLE_INPUT_SIZE] = { '\0' };
    ENUM_TYPE nul = NULLVAL;
    for (int i = 0; i < nbCol; i++) {
        add_col(tab, i, title,nul);
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
        printf("Le CDataframe doit être vide...\n");
        return;
    }
    char title[TITLE_INPUT_SIZE];
    ENUM_TYPE type = NULLVAL;
    for (int i = 0; i < nbCol; i++) {
        do {
            printf("Saisir le nom de la colonne %d : ", i);
        } while (!scanf("%s", title));
        do {
            printf("Saisir le type de la colonne\n(entier non signé : 2, entier : 3, caractere : 4, float : 5, double : 6, chaine de caracteres : 7) : ");
        } while (!scanf("%d", type) || !(type >= UINT && type <= STRING));
        add_col(tab, i, title,type);
        switch (type) {
        case UINT:
            unsigned int value = 0;
            for (int j = 0; j < nbLine; j++) {
                do {
                    printf("Saisir la valeur en colonne %d ligne %d : ", i, j);
                } while (!scanf("%d", &value));
                set_value(tab, i, j, (void*)&value);
            }
        case INT:
            int value = 0;
            for (int j = 0; j < nbLine; j++) {
                do {
                    printf("Saisir la valeur en colonne %d ligne %d : ", i, j);
                } while (!scanf("%d", &value));
                set_value(tab, i, j, (void*)&value);
            }
        case CHAR:
            char value = 0;
            for (int j = 0; j < nbLine; j++) {
                do {
                    printf("Saisir la valeur en colonne %d ligne %d : ", i, j);
                } while (!scanf("%c", &value));
                set_value(tab, i, j, (void*)&value);
            }
        case FLOAT:
            float value = 0.0;
            for (int j = 0; j < nbLine; j++) {
                do {
                    printf("Saisir la valeur en colonne %d ligne %d : ", i, j);
                } while (!scanf("%f", &value));
                set_value(tab, i, j, (void*)&value);
            }
        case DOUBLE:
            double value = 0.0;
            for (int j = 0; j < nbLine; j++) {
                do {
                    printf("Saisir la valeur en colonne %d ligne %d : ", i, j);
                } while (!scanf("%lf", &value));
                set_value(tab, i, j, (void*)&value);
            }
        case STRING:
            char str[TITLE_INPUT_SIZE] = { '\0' };
            for (int j = 0; j < nbLine; j++) {
                do {
                    printf("Saisir la valeur en colonne %d ligne %d : ", i, j);
                } while (!scanf("%s", value));
                set_value(tab, i, j, (void*)value);
            }
        }
        
    }
}