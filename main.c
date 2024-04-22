/*
Exemple d'utilisation du CDataframe
*/

#include "CDataframe.h"
#include "stdio.h"

int main() {
	CDataframe* tab = new_cdataframe();
	int choice;
	int line;
	int col;
	for (;;) {
		printf("Select an action :\n1.\tAdd a line\n2.\tAdd a column\n3.\tDelete a line\n4.\tDelete a column\n5.\tSet a value\n6.\tPrint the table\n7.\tQuitte...\nYour action (1/2/3/4/5/6/7) : ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			add_line(tab);

		case 2:
			add_col(tab);
		case 3:
			printf("Which line will you delete ? : ");
			scanf("%d", &line);
			del_line(tab,line);
		case 4:
			printf("Which column will you delete ? : ");
			scanf("%d", &col);
			del_col(tab,col);
		case 5:
			set_value_input(*tab);
		case 6:
			print_cdata(*tab);
		case 7:
			return 0;
		default:
			printf("This action doesn't exist, please try again.\n");
		}
	}
	return 1;
}
