#include <stdio.h>
#include <locale.h>
#include "Funcs.h"

int main(int argn, char* argv[]) {
	setlocale(0, "rus");
	if (argn < 2) {
		printf("������: ��� ������ ��� ������\n");
		return 1;
	}
	FILE* ofile = fopen("Output.txt", "w");
	int c;
	int pagecounter = 1;
	for (int i = 1; i < argn; i++) {
		FILE* fp = fopen(argv[i], "r");
		fprintf(ofile, "==================%d==================\n", pagecounter++);
		fprintf(ofile, "����:%s\n", argv[i]);
		while ((c = fgetc(fp)) != EOF) {
			fputc(c, ofile);
		}
		fprintf(ofile, "\n");
	}
	printf("��������� ���������� �������, �������\n");
	return 0;
}