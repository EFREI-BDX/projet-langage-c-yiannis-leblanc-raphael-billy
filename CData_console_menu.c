#include "CDataframe.h"

enum Commande {
	NULLVAL = 0,
	TAB_AUTO, TAB_MANUEL,
	SET_VAL,
	SET_NAME,
	ADD_COL,
	DEL_COL,
	ADD_LINE,
	DEL_LINE,
	PRINT,
	PRINT_COL,
	PRINT_LINE,
	QUIT

};
typedef enum Commande Commande;

void menu() {
	printf("********************\nCDataframe partie I par Yiannis et Raphael\n********************\n\n");
	printf("Attention :\n\nDans ce CDataframe les colonnes et les lignes sont numerotees a partir de 0,\n\nIl est tout a fait possible de saisir une valeur sur des coordonnees qui n'existent pas encore,\n\nLe programme pourra ajouter des colonnes ou des lignes vierges si besoin,\n\nPar defaut les valeurs non renseignees valent 0.\n\nBonne experience !\n\n");
	CDataframe tab = new_cdataframe();
	Commande choix = NULLVAL;
	for (int i = 0; i < 3; i++) {
		Sleep(1000);
		printf(".");
	}
	printf("\n");
	printf("Votre CDataframe est vide, choisissez parmi l'une de ces commandes : \n\n");
	printf("1 : Creer un tableau a partir de valeurs par defaut.\n");
	printf("2 : Creer un tableau a partir de valeurs saisies.\n\n");
	do { 
		printf("Saisissez l'une des deux propositions (seulement le chiffre) : "); 
	} while (!scanf("%d", &choix) || !(choix == TAB_AUTO || choix == TAB_MANUEL));
	switch (choix) {
	case TAB_AUTO:
		fill_blank_cdata_input(&tab);
		break;
	case TAB_MANUEL:
		fill_cdata_input(&tab);
		break;
	default:
		printf("Une erreur s'est produite...\n");
		return;
	}
	printf("\n");
	int input = 0;
	for (;;) {
		printf("Choisissez une commande parmi l'une de ces commandes :\n\n");
		printf("3 : Modifier une valeur.\n");
		printf("4 : Renommer une colonne.\n");
		printf("5 : Ajouter une colonne.\n");
		printf("6 : Supprimer une colonne.\n");
		printf("7 : Ajouter une ligne.\n");
		printf("8 : Supprimer un ligne.\n");
		printf("9 : Afficher le tableau.\n");
		printf("10 : Afficher une partie des colonnes.\n");
		printf("11 : Afficher une partie des lignes.\n");
		printf("12 : Quitter le programme...\n\n");
		do {
			printf("Saisir l'une des commandes (seulement le numero) : ");
		} while (!scanf("%d", &choix) || !(choix >= SET_VAL && choix <= QUIT));
		switch (choix) {
		case SET_VAL:
			set_value_input(&tab);
			break;
		case SET_NAME:
			rename_cdata_col_input(tab);
			break;
		case ADD_COL:
			add_col_input(&tab);
			break;
		case DEL_COL:
			do {
				printf("Saisir la colonne a supprimer : ");
			} while (!scanf("%d", &input) || input < 0);
			del_col(&tab, input);
			break;
		case ADD_LINE:
			do {
				printf("Saisir position de la nouvelle ligne : ");
			} while (!scanf("%d", &input) || input < 0);
			add_line(tab, input);
			break;
		case DEL_LINE:
			do {
				printf("Saisir position de la ligne à supprimer : ");
			} while (!scanf("%d", &input) || input < 0);
			del_line(tab, input);
			break;
		case PRINT:
			print_cdata(tab);
			for (int i = 0; i < 3; i++) {
				Sleep(1000);
				printf(".");
			}
			printf("\n");
			break;
		case PRINT_COL:
			print_cdata_col_input(tab);
			for (int i = 0; i < 3; i++) {
				Sleep(1000);
				printf(".");
			}
			printf("\n");
			break;
		case PRINT_LINE:
			print_cdata_lines_input(tab);
			for (int i = 0; i < 3; i++) {
				Sleep(1000);
				printf(".");
			}
			printf("\n");
			break;
		case QUIT:
			printf("A bientot");
			
			for (int i = 0; i < 3; i++) {
				Sleep(1000);
				printf(".");
			}
			Sleep(1000);
			return;
		default :
			printf("Une erreur s'est produite");
			for (int i = 0; i < 3; i++) {
				Sleep(1000);
				printf(".");
			}
			printf("\n");
			return;
		}
		printf("\n");
	}
	return;
}