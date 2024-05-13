#include "CDataframe.h"

CDataframe* new_cdataframe() {
	return NULL;
}

void fill_blank_cdata(CDataframe tab, int nbCol, int nbLine) {
}

void print_cdata_col_input(CDataframe tab) {
}

void fill_cdata_input(CDataframe tab, int nbCol, int nbLine) {
}

void set_value_input(CDataframe tab) {
    int col;
    int ligne;
    Data x;
    printf("Dans quelle colonne ? : ");
    scanf("%d" , &col);
    printf("A quelle ligne ? : ");
    scanf("%d" , &ligne);
    printf("Quelle valeur ? : ");
    scanf("%d" , &x);
    set_value(tab, col, ligne, x);
}

void print_cdata_lines_input(CDataframe tab) {
    int line1;
    int line2;
    printf("De quelle ligne à quelle ligne voulez-vous afficher ? : ");
    scanf("%d %d", &line1, &line2);
    print_cdata_lines(tab, line1, line2);
}

void set_value(CDataframe tab, int col, int line, Data x) {
    if col > nb_colonne(tab) || line > nb_colonne(line) {
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
}

void add_line(CDataframe* tab) {
}

void del_line(CDataframe* tab, int line) {
}

void add_col(CDataframe* tab) { 
    CDLink* new_link = (CDLink*)malloc(sizeof(CDLink));
    if (new_link == NULL) return;
    
    Column* new_col = (Column*)malloc(sizeof(Column));
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
    free(temp->col->values);
    free(temp->col);
    free(temp);
}

void rename_cdata_col(CDataframe tab, int col) {
}

int in_cdata(CDataframe tab, Data x) {
	return 0;
}

int nb_ligne(CDataframe tab) {
	return 0;
}

int nb_colonne(CDataframe tab) {
	return 0;
}

int nb_equal_cdata(CDataframe tab, Data x) {
	return 0;
}

int nb_higher_cdata(CDataframe tab, Data x) {
	return 0;
}

int nb_lower_cdata(CDataframe tab, Data x) {
	return 0;
}
