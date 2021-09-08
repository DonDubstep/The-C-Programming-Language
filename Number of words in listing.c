#include <stdio.h>
#include <locale.h>
//для чтения необходимо создать файл Read.txt и поместить его в этот репозиторий
//В Read.txt заносится весь код

struct key {
	char* word;
	int count;
}
keytab[] = {		//все ключевые слова
	"auto", 0,
	"break", 0,
	"case", 0,
	"char", 0,
	"const", 0,
	"continue", 0,
	"default", 0,
	"do", 0,
	"double", 0,
	"else", 0,
	"enum", 0,
	"extern", 0,
	"float", 0,
	"for", 0,
	"goto", 0,
	"if", 0,
	"include", 0,
	"inline", 0,
	"int", 0,
	"long", 0,
	"register", 0,
	"return", 0,
	"short", 0,
	"signed", 0,
	"sizeof", 0,
	"static", 0,
	"struct", 0,
	"switch", 0,
	"typedef", 0,
	"union", 0,
	"unsigned", 0,
	"void", 0,
	"while", 0
};

#define Nkeys (sizeof(keytab) / sizeof(struct key))
#define MaxLen 500
#define CODE 0			//обычный код
#define STRCOMM 1		//комменты типа "//"
#define BLOCKCOMM 2		//комменты типа "/**/"

int state;				//состояние кода (комменты или нет)

int binsearchInMassOfStruct(char* word, struct key table[], int n);

int main(int argc, char* argv[])
{
	setlocale(0, "Rus");
	char text[MaxLen];			//массив для записи строк из файла
	FILE* wxe = fopen("D:\\Read.txt", "r");
	int textPos;
	char word[MaxLen];			//для хранения слов из text
	state = CODE;
	while (fgets(text, MaxLen, wxe)) {
		textPos = 0;
		if (state == STRCOMM)
			state = CODE;
		while (getword(text + textPos, &textPos, word)) {
			int index;
			if (state != CODE) continue;
			if ((index = binsearchInMassOfStruct(word, keytab, Nkeys)) != -1)
				keytab[index].count++;
		}
	}
	int nkeywords = 0;
	for (int i = 0; i < Nkeys; i++)
		nkeywords += keytab[i].count;
	printf("Количество ключевых слов в программе = %d", nkeywords);
	fclose(wxe);
	return 0;
}

//бинарный поиск слова в массиве keytble
int binsearchInMassOfStruct(char* searchWord, struct key table[], int n) {
	int low, mid, high;
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (strcmp(searchWord, table[mid].word) > 0)
			low = mid + 1;
		else if (strcmp(searchWord, table[mid].word) < 0)
			high = mid - 1;
		else return mid;
	}
	return -1;
}

//получение слова из строки strsymb в result
int getword(char* strsymb, int* textPos, char* result) {
	while (!isalpha(*strsymb)) {
		if (*strsymb == '\0')
			return 0;
		if (*strsymb == '/') {
			if (*++strsymb == '/')
				state = STRCOMM;
			else if (*strsymb == '*')
				state = BLOCKCOMM;
			else --strsymb;
		}
		else if (*strsymb == '*' && state == BLOCKCOMM) {
			if (*++strsymb == '/')
				state = CODE;
			else --strsymb;
		}
		strsymb++;
		(*textPos)++;
	}
	while (isalpha(*strsymb) && *strsymb != '\0') {
		*result++ = *strsymb++;
		(*textPos)++;
	}
	*result = '\0';
	return 1;
}

