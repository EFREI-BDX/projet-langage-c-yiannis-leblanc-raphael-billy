/*
Exemple d'utilisation du CDataframe
*/

#include "cdataframe.h"
#include "stdio.h"

int main() {
	CDataframe tab = new_cdataframe();
	fill_blank_cdata(&tab, 5, 5);
	print_cdata(tab);
	set_value(&tab, 3, 1, 18);
	add_col(&tab, 3, "colX");
	print_cdata(tab);
	return 0;
}
