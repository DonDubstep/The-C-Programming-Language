#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#define MaxLen 100

int mystrlen(char[]);									//выдает длину строки
void mystrcat(char*, char*);							//конкатенация строк
void mystrcpy(char*, char*);							//копирует символы из одной строки в другую
int strcmp(char* s1, char* s2);						//сравнение строк
int strend(char*, char*);							//сравнение строк
char* strncpy(char* to, char* from, int n);			//копирует n первых символов из одной строки в другую
char* strncat(char* to, char* from, int n);			//конкатенация n первых строк
char mystrncmp(char* s1, char* s2, int n);			//сравнение первых n строк
int getline(char* s, int lim);						//ввод строки с ограничением в lim символов (стоп символы: '\n' & '`')
int myatoi(char s[]);									//перевод строки в int
void myitoa(int n, char s[]);							//перевод числа int в строку
void reverse(char s[]);								//"переворот" строки
int strindex(char base[], char part[]);					//вычисляет место part в base или выдает -1, если part нет в base
void to_dayAndMonth(int year, int yearDay, int* pmonth, int* pday);		//определяет день и месяц по дню года
int to_yearDay(int year, int month, int day);							//определяет день года по дню и месяцу
char* monthName(int n);								//возвращает название n-го месяца
int pop();											//достать элемент из стека
void push(int n);									//положить элемент в стек
void tail(char str[], int n);						//печать последних n символов строки str
int getword(char* strsymb, int* textPos, char* result);		//получение из строки str слова в result (indexOfLastWord - позиция начального слова в str)
int binsearch(int x, int mass[], int n);		//бинарный поиск индекса числа x в массиве mass 
struct tnode* addtree(struct tnode* pnode, char* word, int nstr);		//рекурсивное добавление слова в бинарное дерево (без повторов)
void treeprint(struct tnode* pnode);						//печать бинарного дерева
char* mystrdup(char* s);										//выделение памяти для слова
int* massdup(int arr);
char myToLower(char c);								//перевод символа в нижний регистр
char myToUpper(char c);								//перевод символа в верхний регистр
void myprintf(char* str, ...);						//printf 
int myscanf(char* fmt, ...);						//scanf



//////////невисокосный год и високосный год
static int daytable[][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};


struct tnode {
	char* word;
	int counter;
	int* nstrings;
	struct tnode* left;
	struct tnode* right;
};