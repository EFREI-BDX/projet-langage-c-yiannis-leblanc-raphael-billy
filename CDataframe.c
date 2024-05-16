#include "CDataframe.h"

CDataframe new_cdataframe() {
	return NULL;
}

CDLink* get_cdlink(CDataframe tab, int col) {
    for (int i = 0; i < col ; i++) {
        if (tab == NULL) return NULL;

        tab = tab->next;
    }
    return tab;
}

void fill_blank_cdata(CDataframe* tab, int nbCol, int nbLine) {
    if (*tab != NULL) return;

    Data value = 0;
    for (int i = 0; i < nbCol; i++) {
        add_col(tab, i);
        for (int j = 0; j < nbLine; j++) {
            set_value(*tab, i, j, value);
        }
    }
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
    if (*tab != NULL) return;

    Data value;
    for (int i = 0; i < nbCol; i++) {
        add_col(tab, i);
        for (int j = 0; j < nbLine; j++) {
            printf("Saisir la valeur en colonne %d ligne %d : ",i,j);
            if(scanf("%d", &value)) set_value(*tab, i, j, value);
        }
    }
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
    if (col > nb_colonne(tab)) return;
    
    CDLink* current_link = tab;
    for (int i = 0; i < col; i++) {
        current_link = current_link->next;
    }
    if (line > current_link->col->logicalSize) return;

    insertValue(current_link->col, x);
    
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
    if (tab == NULL) return;

    CDataframe subTab = get_cdlink(tab,col1);
    CDLink* temp=subTab;
    for (int i = 0; i < col1; i++) {
        if (temp == NULL) return;

        printf("%s\t", temp->col->title);
        temp = temp->next;
    }
    for (int i = 0; i < nb_ligne(tab);i++) {
        temp = subTab;
        for (int j = col1; j <= col2; j) {
            if (i < temp->col->logicalSize) printf("%d", temp->col->values[i]);
            temp = temp->next;
        }
    }
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

void add_line(CDataframe tab,int line) {
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
            for (int i = line; i < (tab->col->logicalSize-1); i++) {
                tab->col->values[i] = tab->col->values[i + 1];
            }
            tab->col->values[tab->col->logicalSize - 1] = 0;
        }
        tab = tab->next;
    }
}

void add_col(CDataframe* tab, int col) {
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
    for (int i = 0; i < col && last->next != NULL; i++) {
        last = last->next;
    }
    CDLink* temp = last->next;
    last->next = new_link;
    new_link->next = temp;
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

void rename_cdata_col_input(CDataframe tab) {
    printf("Quelle colonne voulez-vous renommer ? : ");
    int col;
    if (!scanf("%d", &col)) return;

    printf("Saisir le nouveau nom de la colonne : ");
    char name[TITLE_INPUT_SIZE];
    if (!scanf("%s", name)) return;

    rename_cdata_col(tab, col, name);
}

void rename_cdata_col(CDataframe tab, int col, char* name) {
    CDLink* link = get_cdlink(tab, col);
    if (link != NULL) strcpy(link->col->title, name);
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
