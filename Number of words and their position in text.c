#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define MaxLen 5000

struct tnode {
	char* word;
	int counter;
	int* nstrings;
	struct tnode* left;
	struct tnode* right;
};

char* strdup(char* s);
int isword(char c);
int* massdup(int arr);
void treeprint(struct tnode* pnode);
int getword(char* str, int* textPos, char* result);
struct tnode* addtree(struct tnode* pnode, char* word, int nstr);

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Rus");
	printf("\t\t\tПрограмма для посчёта количества слов и расположения их в тексте\n");
	printf("\t\t\t\t\tИспользовать кодировку ANSI\n\n");
	FILE* wxe = fopen("D:\\Read.txt", "r");
	char text[MaxLen];
	char word[MaxLen];
	struct tnode* root = NULL;
	int strPos;
	int nstr = 0;
	while (fgets(text, MaxLen, wxe)) {
		strPos = 0;
		nstr++;
		while (getword(text + strPos, &strPos, word)) {
			root = addtree(root, word, nstr);
		}
	}
	printf("Количество                   Слово    Строки\n");
	treeprint(root);
	fclose(wxe);
	return 0;
}



char* strdup(char* s) {
	char* p;
	p = (char*)malloc(strlen(s) + 1);
	if (p != NULL)
		strcpy(p, s);
	return p;
}

int* massdup(int arr) {
	int* temp;
	temp = (int)malloc(sizeof(int));
	*temp = arr;
	return temp;
}

struct tnode* addtree(struct tnode* pnode, char* word, int nstr) {
	int rescom;
	if (pnode == NULL) {
		pnode = (struct tnode*)malloc(sizeof(struct tnode));
		pnode->word = strdup(word);
		pnode->nstrings = massdup(nstr);
		pnode->counter = 1;
		pnode->left = pnode->right = NULL;
	}
	else if ((rescom = strcmp(pnode->word, word, nstr)) == 0) {
		pnode->counter++;
		*(++pnode->nstrings) = nstr;
	}
	else if (rescom < 0)
		pnode->left = addtree(pnode->left, word, nstr);
	else
		pnode->right = addtree(pnode->right, word, nstr);
	return pnode;
}

void treeprint(struct tnode* pnode) {
	if (pnode != NULL) {
		treeprint(pnode->left);
		printf("%20d %13s    ", pnode->counter, pnode->word);
		pnode->nstrings = pnode->nstrings - pnode->counter + 1;
		for (int i = 0; i < pnode->counter; i++)
			printf("%d ", *(pnode->nstrings)++);
		printf("\n");
		treeprint(pnode->right);
	}
}

int getword(char* str, int* textPos, char* result) {
	while (!isword(*str)) {
		if (*str == '\0')
			return 0;
		str++;
		(*textPos)++;
	}
	while (isword(*str) && *str != '\0') {
		*result++ = *str++;
		(*textPos)++;
	}
	*result = '\0';
	return 1;
}

int isword(char c) {
	return (c >= 65 && c <= 90 || c >= 97 && c <= 122 || c >= -64 && c <= -1) ? 1 : 0;
}