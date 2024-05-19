/*
Exemple d'utilisation du CDataframe
*/

#include "CDataframe.h"
#include "stdio.h"

int main() {
	CDataframe tab = new_cdataframe();
	
	fill_cdata_input(&tab);
	print_cdata(tab);
	printf("FIN\n");
	del_col(&tab, 2);
	print_cdata(tab);
	return 0;
}
