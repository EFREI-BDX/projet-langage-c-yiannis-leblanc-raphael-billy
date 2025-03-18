#include "CDataframe.h"

void set_value_input(CDataframe* tab) {
    int col;
    int ligne;
    Data x;
    do {
        printf("Veuiller saisir la colonne, la ligne, et la valeur (col ligne val) : ");
    } while ((scanf("%d %d %d", &col, &ligne, &x) < 3) || col < 0 || ligne < 0);

    set_value(tab, col, ligne, x);
}

void set_value(CDataframe* tab, int col, int line, Data x) {
    if (col > (nb_colonne(*tab)) - 1) {
        char vide[TITLE_INPUT_SIZE] = { '\0' };
        add_col(tab, col, vide);
    }
    CDLink* current_link = get_cdlink(*tab, col);
    for (int i = (current_link->col->logicalSize - 1); i < line; i++) insertValue(current_link->col, 0);
    current_link->col->values[line] = x;
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