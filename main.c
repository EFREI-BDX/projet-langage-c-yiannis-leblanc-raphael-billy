/*
Exemple d'utilisation du CDataframe
*/

#include "CDataframe.h"
#include "stdio.h"

int main() {
	ENUM_TYPE type = INT;
	Column* col = createColumn(type, "Test");
	int val;
	for (int i = 0; i < 5; i++) {
		val = i;
		insertValue(col, (void*) &val);
	}
	print_col(col);
	return 0;
}
