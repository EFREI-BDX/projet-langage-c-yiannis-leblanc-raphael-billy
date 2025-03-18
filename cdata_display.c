#include "CDataframe.h"

void print_cdata_col_input(CDataframe tab) {
    int col1, col2;
    do {
        printf("Saisir les premiere et derniere colonne affichees (a b) : ");
    } while (scanf("%d %d", &col1, &col2) < 2 || col1 > col2 || col1 < 0 || col2 < 0);
    print_cdata_col(tab, col1, col2);
}

void print_cdata_lines_input(CDataframe tab) {
    int line1;
    int line2;
    do {
        printf("De quelle ligne a quelle ligne voulez-vous afficher (a b) : ");
    } while ((scanf("%d %d", &line1, &line2) != 2) || line1 > line2 || line1 < 0 || line2 < 0);
    print_cdata_lines(tab, line1, line2);
}

void print_cdata(CDataframe tab) {
    print_cdata_col(tab, 0, nb_colonne(tab) - 1);
}

void print_cdata_lines(CDataframe tab, int line1, int line2) {
    if (tab == NULL) {
        printf("Impossible d'afficher un CDataframe vide...");
        return;
    }

    CDLink* sub_tab;
    for (int j = line1; j <= line2; j++) {
        sub_tab = tab;
        do {
            if (j < sub_tab->col->logicalSize) {
                printf("%d", sub_tab->col->values[j]);
            }
            printf("\t");
            sub_tab = sub_tab->next;
        } while (sub_tab->next != NULL);
        printf("\n");
    }
}

void print_cdata_col(CDataframe tab, int col1, int col2) {
    if (tab == NULL) {
        printf("Impossible d'afficher un CDtaframe vide...");
        return;
    }

    CDataframe subTab = get_cdlink(tab, col1);
    CDLink* temp = subTab;
    for (int i = col1; i <= col2 && temp != NULL; i++) {
        printf("%s\t", temp->col->title);
        temp = temp->next;
    }
    printf("\n");
    for (int i = 0; i < nb_ligne(tab); i++) {
        temp = subTab;
        for (int j = col1; j <= col2 && temp != NULL; j++) {
            if (i < temp->col->logicalSize) printf("%d", temp->col->values[i]);
            printf("\t");
            temp = temp->next;
        }
        printf("\n");
    }
}

void print_col_names(CDataframe tab) {
    if (tab == NULL) {
        printf("Impossible d'afficher un CDataframe vide...\n");
        return;
    }

    int i = 0;
    CDLink* maillon = tab;
    while (maillon != NULL) {
        printf("colonne numero %d : %s\t", i++, maillon->col->title);
        maillon = maillon->next;
    }
    printf("\n");
}