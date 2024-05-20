#include "CDataframe.h"

void set_value_input(CDataframe* tab) { // à corriger
    int col;
    int ligne;
    CDLink* Link = get_cdlink(*tab, col);
    do {
        printf("Saisir la colonne et la ligne de la valeur (a b) : ");
    } while(scanf("%d %d",&col, &ligne < 2) || col < 0 || ligne < 0);
    switch (Link->col->type) {
    case UINT:
        unsigned int value;
        do {
                printf("Saisir la valeur en colonne %d ligne %d : ", col, ligne);
            } while (!scanf("%d", &value));
            set_value(tab, col, ligne, (void*)&value);
        
    case INT:
        int value;
        do {
                printf("Saisir la valeur en colonne %d ligne %d : ", col, ligne);
            } while (!scanf("%d", &value));
            set_value(tab, col, ligne, (void*)&value);
        
    case CHAR:
        char value;
        do {
                printf("Saisir la valeur en colonne %d ligne %d : ", col, ligne);
            } while (!scanf("%c", &value));
            set_value(tab, col, ligne, (void*)&value);
        
    case FLOAT:
        float value;
        do {
                printf("Saisir la valeur en colonne %d ligne %d : ", col, ligne);
            } while (!scanf("%f", &value));
            set_value(tab, col, ligne, (void*)&value);
        
    case DOUBLE:
        double value;
        do {
                printf("Saisir la valeur en colonne %d ligne %d : ", col, ligne);
            } while (!scanf("%lf", &value));
            set_value(tab, col, ligne, (void*)&value);
        
    case STRING:
        char str[TITLE_INPUT_SIZE];
        do {
                printf("Saisir la valeur en colonne %d ligne %d : ", col, ligne);
            } while (!scanf("%s", value));
            set_value(tab, col, ligne, (void*)value);
        
    }
}

void set_value(CDataframe* tab, int col, int line, void* x) {
    if (col > (nb_colonne(*tab)) - 1) {
        ENUM_TYPE nul = NULLVAL;
        char vide[TITLE_INPUT_SIZE] = { '\0' };
        add_col(tab, col, vide,nul);
    }
    CDLink* current_link = get_cdlink(*tab, col);
    for (int i = (current_link->col->logicalSize - 1); i < line; i++) insertValue(current_link->col, NULL);
    set_col_value(current_link->col, line, x);
}

void rename_cdata_col_input(CDataframe tab) {
    int col;
    do {
        printf("Quelle colonne voulez-vous renommer ? : ");
    } while ((!scanf("%d", &col)) || col < 0);
    char name[TITLE_INPUT_SIZE];
    do {
        printf("Saisir le nouveau nom de la colonne : ");
    } while (!scanf("%s", name));
    rename_cdata_col(tab, col, name);
}

void rename_cdata_col(CDataframe tab, int col, char* name) {
    CDLink* link = get_cdlink(tab, col);
    if (link != NULL) strcpy(link->col->title, name);
}