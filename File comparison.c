#include <stdio.h>
#include <locale.h>
#include "Funcs.h"

int main(int argn, char* argv[]) {
	setlocale(0, "rus");
	if (argn != 3) {
		printf("Необходимо 2 файла для проверки\n");
		return 1;
	}
	char diffstr[MaxLen];
	int d;
	FILE* fp1 = fopen(argv[1],"r");
	FILE* fp2 = fopen(argv[2], "r");
	char c1 = getc(fp1);
	char c2 = getc(fp2);
	d = 0;
	while (c1 == c2 && c1 != EOF && c2 != EOF) {
		if (c1 == ' ') {
			diffstr[0] = '\0';
			d = 0;
		}
		diffstr[d++] = c1;
		c1 = getc(fp1);
		c2 = getc(fp2);
	}
	if (c1 != c2) {
		diffstr[d++] = c1;
		if (c1 == ' ') {
			diffstr[0] = '\0';
			d = 0;
		}
		while (c1 == ' ')
			c1 = getc(fp1);
		while (c1 != ' ' && c1 != EOF) {
			diffstr[d++] = c1;
			c1 = getc(fp1);
		}
		diffstr[d] = '\0';
		printf("Первое различное слово: %s\n", diffstr);
		return 0;
	}
	printf("Содержимое файлов не различается\n");
	return 0;
}