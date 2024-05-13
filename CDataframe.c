#include "CDataframe.h"

CDataframe* new_cdataframe() {
	return NULL;
}

void fill_blank_cdata(CDataframe* tab, int nbCol, int nbLine)
{
}

void fill_blank_cdata_input(CDataframe* tab) {
    int nbCol, nbLine;
    printf("Saisir le nombre de colonnes : ");
    if (!scanf("%d", &nbCol)) return;

    printf("Saisir le nombre de lignes : ");
    if (!scanf("%d", &nbLine)) return;

    fill_blank_cdata(tab, nbCol, nbLine);
}

void print_cdata_col_input(CDataframe tab) {
    int col1, col2;
    printf("Saisir le premier indice : ");
    if (!scanf("%d", &col1)) return;

    printf("Saisir le dernier indice : ");
    if (!scanf("%d", &col2)) return;

    if (col1 < 0 || col2<0 || col1>col2) {
        printf("Les valeurs sont non conformes...\n");
        return;
    }

    print_cdata_col(tab, col1, col2);
}

void fill_cdata_input(CDataframe* tab) {
    int nbCol, nbLine;
    printf("Saisir le nombre de colonnes : ");
    if (!scanf("%d", &nbCol)) return;

    printf("Saisir le nombre de lignes : ");
    if (!scanf("%d", &nbLine)) return;

    fill_cdata(tab, nbCol, nbLine);
}

void fill_cdata(CDataframe* tab, int nbCol, int nbLine) {

    return;
}

void set_value_input(CDataframe tab) {
    int col;
    int ligne;
    Data x;
    printf("Dans quelle colonne ? : ");
    if (!scanf("%d" , &col)) return;

    printf("A quelle ligne ? : ");
    if (!scanf("%d" , &ligne)) return;

    printf("Quelle valeur ? : ");
    if (!scanf("%d" , &x)) return;

    set_value(tab, col, ligne, x);
}

void print_cdata_lines_input(CDataframe tab) {
    int line1;
    int line2;
    printf("De quelle ligne à quelle ligne voulez-vous afficher ? : ");
    if (scanf("%d %d", &line1, &line2)!=2) return;
    print_cdata_lines(tab, line1, line2);
}

void set_value(CDataframe tab, int col, int line, Data x) {
    if (col > nb_colonne(tab) || line > nb_ligne(tab)) {
        printf("Erreur : la ligne ou la colonne n'existe pas\n");
        return;
    }
    else {
        CDLink* current_link = tab;
        for (int i = 0; i < col; i++) {
            current_link = current_link->next;
        }
        insertValue(current_link->col, x);
    }
}

void print_cdata(CDataframe tab) {
    print_cdata_col(tab, 0, nb_colonne(tab)-1);
}

void print_cdata_lines(CDataframe tab, int line1, int line2) {
	if (tab == NULL) return;

	CDLink* sub_tab;
	for (int j = line1 ; j<=line2;j++){
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

}

void print_col_names(CDataframe tab) {
    if (tab == NULL) return;
    int i =0;
    CDLink* maillon = tab;
    while (maillon != NULL) {
        printf("colonne numéro %d : %s\t", i++, maillon->col->title);
        maillon = maillon->next;
    }
    printf("\n");
}

void add_line(CDataframe* tab) {

}

void del_line(CDataframe* tab, int line) {

}

void add_col(CDataframe* tab) {
    CDLink* new_link = (CDLink*)malloc(sizeof(CDLink));
    if (new_link == NULL) return;

    printf("Saisir le nom de la colonne : ");
    char name[TITLE_INPUT_SIZE];
    if (!scanf("%s", name)) {
        free(new_link);
        return;
    }

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
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_link;
}

void del_col(CDataframe* tab, int col) {
    if (*tab == NULL) return;

    CDLink** previous = tab;
    for (int i = 0; i <= (col-1); i++) {
        if ((*previous)->next == NULL) return;

        previous = &(*previous)->next;
    }
    CDLink* temp = (*previous)->next;
    (*previous) = temp->next;
    delete_column(&temp->next);
    free(temp);
}

void rename_cdata_col(CDataframe tab, int col) {
}

int in_cdata(CDataframe tab, Data x) {
    if(nb_equal_cdata(tab, x)>0){
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
	return 0;
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
