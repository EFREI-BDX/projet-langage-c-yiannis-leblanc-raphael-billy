/*
Exemple d'utilisation du CDataframe
*/

#include "CDataframe.h"
#include "stdio.h"

int main() {
	ENUM_TYPE type = INT;
	Column* col = createColumn(type, "Gros caca.");
	Data val = { .int_value = 0 };
	for (int i = 0; i < 5; i++) {
		val.int_value = i;
		insertValue(col, val);
	}
	print_col(col);
	return 0;
}
