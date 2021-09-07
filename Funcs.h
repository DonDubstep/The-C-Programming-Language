#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#define MaxLen 100

int mystrlen(char[]);									//����� ����� ������
void mystrcat(char*, char*);							//������������ �����
void mystrcpy(char*, char*);							//�������� ������� �� ����� ������ � ������
int strcmp(char* s1, char* s2);						//��������� �����
int strend(char*, char*);							//��������� �����
char* strncpy(char* to, char* from, int n);			//�������� n ������ �������� �� ����� ������ � ������
char* strncat(char* to, char* from, int n);			//������������ n ������ �����
char mystrncmp(char* s1, char* s2, int n);			//��������� ������ n �����
int getline(char* s, int lim);						//���� ������ � ������������ � lim �������� (���� �������: '\n' & '`')
int myatoi(char s[]);									//������� ������ � int
void myitoa(int n, char s[]);							//������� ����� int � ������
void reverse(char s[]);								//"���������" ������
int strindex(char base[], char part[]);					//��������� ����� part � base ��� ������ -1, ���� part ��� � base
void to_dayAndMonth(int year, int yearDay, int* pmonth, int* pday);		//���������� ���� � ����� �� ��� ����
int to_yearDay(int year, int month, int day);							//���������� ���� ���� �� ��� � ������
char* monthName(int n);								//���������� �������� n-�� ������
int pop();											//������� ������� �� �����
void push(int n);									//�������� ������� � ����
void tail(char str[], int n);						//������ ��������� n �������� ������ str
int getword(char* strsymb, int* textPos, char* result);		//��������� �� ������ str ����� � result (indexOfLastWord - ������� ���������� ����� � str)
int binsearch(int x, int mass[], int n);		//�������� ����� ������� ����� x � ������� mass 
struct tnode* addtree(struct tnode* pnode, char* word, int nstr);		//����������� ���������� ����� � �������� ������ (��� ��������)
void treeprint(struct tnode* pnode);						//������ ��������� ������
char* mystrdup(char* s);										//��������� ������ ��� �����
int* massdup(int arr);
char myToLower(char c);								//������� ������� � ������ �������
char myToUpper(char c);								//������� ������� � ������� �������
void myprintf(char* str, ...);						//printf 
int myscanf(char* fmt, ...);						//scanf



//////////������������ ��� � ���������� ���
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