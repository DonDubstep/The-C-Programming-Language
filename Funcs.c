#include "Funcs.h"

void mystrcat(char* to, char* from) {
	while (*to)
		to++;
	while (*to++ = *from++);
	*to = '\0';
}

void mystrcpy(char* s, char* t) {
	while (*s++ = *t++);
}

int mystrlen(char mass[]) {
	char* endmass = mass;
	for (; *endmass != '\0';)
		endmass++;
	return endmass - mass;
}

int strend(char* base, char* example) {
	char* basecopy = base;
	char* examplecopy = example;
	while (*basecopy != '\0') {
		while (*base++ != *example && *base != '\0');
		base--;
		basecopy = base;
		while (*base++ == *example++)
			if (*base == '\0' && *example == '\0')
				return 1;
		example = examplecopy;
		base = ++basecopy;
	}
	return 0;
}

char* strncpy(char* to, char* from, int n) {
	while ((*to++ = *from++) && n--);
	*to = '\0';
	return to;
}

char* strncat(char* to, char* from, int n) {
	while (*to)
		to++;
	while ((*to++ = *from++) && n--);
	*to = '\0';
	return to;
}

char mystrncmp(char* s1, char* s2, int n) {
	while ((*s1 == *s2) && n--) {
		if (*s1 == '\0' && *s2 == '\0')
			return 0;
		s1++; s2++;
	}
	return *--s1 - *--s2;
}

int getline(char* s, int lim) {
	int counter = 0;
	while (lim-- && ((*s = getchar()) != '`') && *s != '\n') {
		s++;
		counter++;
	}
	*s = '\0';
	return counter;
}

int myatoi(char s[]) {
	int sign;
	int n = 0;
	while (isspace(*s))
		s++;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '+' || *s == '-') /* пропуск знака */
		s++;
	while(isdigit(*s))
		n = 10 * n + (*s++ - '0');
	return sign * n;
}

void myitoa(int n, char s[]) {
	int sign;
	int i = 0;
	if ((sign = n) < 0)
		n = -n;
	do {
		*(s + i++) = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		*(s + i++) = '-';
	*(s + i) = '\0';
	reverse(s);
}


void reverse(char s[])
{
	int temp, i, j;
	for (i = 0, j = mystrlen(s) - 1; i < j; i++, j--) {
		temp = *(s + i);
		*(s + i) = *(s + j);
		*(s + j) = temp;
	}
}

int strindex(char base[], char part[]) {
	int i, j, k;
	for (i = 0; *(base + i) != '\0'; i++) {
		for (j = i, k = 0; *(part + k) != '\0' && *(base + j) == *(part + k); j++, k++)
			;
		if (k > 0 && *(part + k) == '\0')
			return i;
	}
	return -1;
}



int to_yearDay(int year, int month, int day) {
	if (year >= 0 && month > 0 && month <= 12 && day > 0 && day <= 31) {
		int leap;
		leap = (year % 4 == 0 && year % 4 != 0 || year % 400 == 0) ? 1 : 0;
		for (int i = 1; i < month; i++)
			day += daytable[leap][i];
		return day;
	}
	else {
		printf("Неверно введены данные\n");
		exit(1);
	}
}



void to_dayAndMonth(int year, int yearDay, int* pmonth, int* pday) {
	if (yearDay > 0 && yearDay <= 366 && year >= 0) {
		int i, leap;
		*pmonth = 0;
		*pday = 0;
		leap = (year % 4 == 0 && year % 4 != 0 || year % 400 == 0) ? 1 : 0;
		for (i = 1; yearDay > daytable[leap][i]; i++)
			yearDay -= daytable[leap][i];
		*pmonth = i;
		*pday = yearDay;
	}
	else {
		printf("Неверно введены данные\n");
		exit(1);
	}
}


char* monthName(int n) {
	static char* name[] = {
		"Неверный месяц", "Январь", "Февраль", "Март", "Апрель", "Май",
		"Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"
	};
	return (n > 0 && n <= 12) ? name[n] : name[0];
}


#define MaxStackLen 1000
char stack[MaxStackLen];
int stackTop = 0;

void push(int n) {
	if (stackTop < MaxStackLen)
		stack[stackTop++] = n;
	else {
		printf("Переполнение стека!\n");
	}
}

int pop() {
	if (stackTop > 0)
		return stack[--stackTop];
	else
		printf("Стек пуст!");
}

void tail(char str[], int n) {
	if (n <= mystrlen(str)) {
		char* strTail = str + (mystrlen(str) - n);
		printf("%s", strTail);
	}
	else
		printf("%s", str);
}

int strcmp(char* s1, char* s2) {
	while (*s1 == *s2) {
		if (*s1 == '\0' && *s2 == '\0')
			return 0;
		s1++; s2++;
	}
	if (*s1 > * s2)
		return 1;
	if (*s1 < *s2)
		return -1;
}

int getword(char* str, int* textPos, char* result) {
	while (!isalpha(*str)) {
		if (*str == '\0')
			return 0;
		str++;
		(*textPos)++;
	}
	while (isalpha(*str) && *str != '\0') {
		*result++ = *str++;
		(*textPos)++;
	}
	*result = '\0';
	return 1;
}

int binsearch(int x, int arr[], int n) {
	int low, mid, high;
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x > arr[mid])
			low = mid + 1;
		else if (x < arr[mid])
			high = mid - 1;
		else return mid;
	}
	return -1;
}

char* mystrdup(char* s) {
	char* p;
	p = (char*)malloc(mystrlen(s) + 1);
	if (p != NULL)
		mystrcpy(p, s);
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
		pnode->word = mystrdup(word);
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
		printf("%10d %13s    ", pnode->counter, pnode->word);
		pnode->nstrings = pnode->nstrings - pnode->counter + 1;
		for (int i = 0; i < pnode->counter; i++)
				printf("%d ", *(pnode->nstrings)++);
		printf("\n");
		treeprint(pnode->right);
	}
}

char myToLower(char c) {
	return (c >= 65 && c <= 90) ? c + 32 : (c >= -64 && c <= -33) ? c + 32 : c;
}

char myToUpper(char c) {
	return (c >= 97 && c <= 122) ? c - 32 : (c >= -32 && c <= -1) ? c - 32 : c;
}


void myprintf(char* str, ...) {
	va_list ap;
	char* pstr;
	char* sval;
	int ival;
	double dval;
	unsigned uval;
	int ecount = 0;
	int ncounter = 0;

	va_start(ap, str);
	for (pstr = str; *pstr; pstr++) {
		if (*pstr != '%') {
			putchar(*pstr);
			continue;
		}
		switch (*++pstr) {
		case 'd':
		case 'i':
			ival = va_arg(ap, int);
			printf("%d", ival);
			break;
		case 'f':
			dval = va_arg(ap, double);
			printf("%f", dval);
			break;
		case 's':
			for (sval = va_arg(ap, char*); *sval; sval++)
				putchar(*sval);
			break;
		case 'o':
			ival = va_arg(ap, int);
			while (ival) {
				push(ival % 8);
				ival /= 8;
				ncounter++;
			}
			while (ncounter) {
				putchar(pop() + '0');
				ncounter--;
			}
			break;
		case 'x':
			ival = va_arg(ap, int);
			while (ival) {
				push(ival % 16);
				ival /= 16;
				ncounter++;
			}
			while (ncounter) {
				int popval = pop();
				switch (popval) {
				case 10:
					putchar('a');
					break;
				case 11:
					putchar('b');
					break;
				case 12:
					putchar('c');
					break;
				case 13:
					putchar('d');
					break;
				case 14:
					putchar('e');
					break;
				case 15:
					putchar('f');
					break;
				default:
					putchar(popval + '0');
					break;
				}
				ncounter--;
			}
			break;
		case 'u':
			uval = va_arg(ap, unsigned);
			printf("%u", uval);
			break;
		case 'c':
			ival = va_arg(ap, char);
			putchar(ival);
			break;
		case 'e':
		case 'E':
			dval = va_arg(ap, double);
			if (dval == 0) {
				printf("%f", dval);
				break;
			}
			if (dval >= 1) {
				while (dval > 10) {
					dval /= 10;
					ecount++;
				}
				printf("%f", dval);
				printf("e+");
				putchar(ecount + '0');
			}
			else {
				while (dval < 1) {
					dval *= 10;
					ecount++;
				}
				printf("%f", dval);
				printf("e-");
				putchar(ecount + '0');
			}
			break;
		case 'g':
		case 'G':
			dval = va_arg(ap, double);
			double temp = dval;
			if (dval == 0) {
				printf("%f", dval);
				break;
			}
			if (dval >= 1) {
				while (dval > 10) {
					dval /= 10;
					ecount++;
				}
				if (ecount > 4) {
					printf("%f", dval);
					printf("e+");
					putchar(ecount + '0');
				}
				else
					printf("%f", temp);
			}
			else {
				while (dval < 1) {
					dval *= 10;
					ecount++;
				}
				if (ecount > 4) {
					printf("%f", dval);
					printf("e-");
					putchar(ecount + '0');
				}
				else
					printf("%f", temp);
			}
			break;
			break;
		default:
			putchar(*pstr);
			break;
		}
	}
	va_end(ap);
}

int myscanf(char* fmt, ...) {
#define AfterD 1
#define BeforeD 0
#define Plus 1
#define Minus 0
	va_list ap;
	char ignorestr[MaxLen];			//для хранения символов для игнора
	char* pignorestr;				//указатель на строку игнора
	char* pstr = fmt;
	char c;							//для считывания символов
	char intmass[MaxLen];			//для хранения числа и последующего перевода в int
	int i, j, n, p = 0;
	int sign;						//знак числа
	int esign;						//знак числа с плавающей запятой
	int mul;						//множитель для перевода в 16-ричную и 8-ричную системы
	char digitflag = BeforeD;		//флаг для корректоной работы %d
	char emass[MaxLen];				//хранение степени числа с плавающей запятой
	int digit;

	char strval[MaxLen];
	int ival;
	double dval;
	unsigned uval;

	va_start(ap, fmt);;
	while (*pstr) {
		if (*pstr != '%') {				//запись символов игнора
			ignorestr[p++] = *pstr++;
			continue;
		}
		ignorestr[p] = '\0';
		pignorestr = ignorestr;
		if (ignorestr && digitflag != AfterD) {
			while ((c = getchar()) == *pignorestr++);	//игнор входных символов
		}
		ignorestr[0] = '\0';
		p = 0;
		digitflag = BeforeD;
		switch (*++pstr) {
		case 'c':
			*va_arg(ap, char*) = c;
			pstr++;
			break;
		case 'd':
		case 'i':
			i = 0;
			if (c == '-') {
				sign = -1;
				c = getchar();
			}
			else if (c == '+') {
				sign = 1;
				c = getchar();
			}
			else sign = 1;
			while (isdigit(c)) {
				intmass[i++] = c;
				c = getchar();
			}
			intmass[i] = '\0';
			ival = atoi(intmass) * sign;
			*va_arg(ap, int*) = ival;
			digitflag = AfterD;
			intmass[0] = '\0';
			pstr++;
			break;
		case 'e':
			i = 0;
			if (c == '-') {
				sign = -1;
				c = getchar();
			}
			else if (c == '+') {
				sign = 1;
				c = getchar();
			}
			else sign = 1;
			while (isdigit(c)) {
				intmass[i++] = c;
				c = getchar();
			}
			if (c == '.' || c == ',') {
				intmass[i++] = ',';
				c = getchar();
			}
			while (isdigit(c)) {
				intmass[i++] = c;
				c = getchar();
			}
			intmass[i] = '\0';
			if (c == 'e') {
				c = getchar();
				if (c == '+')
					esign = Plus;
				else if (c == '-')
					esign = Minus;
				c = getchar();
				j = 0;
				while (isdigit(c)) {
					emass[j++] = c;
					c = getchar();
				}
				emass[j] = '\0';
				dval = atof(intmass);
				ival = atoi(emass);
				mul = 1;
				while (ival) {
					mul *= 10;
					ival--;
				}
				if (esign == Plus)
					dval *= mul;
				else if (esign == Minus)
					dval /= mul;
			}
			else
				dval = atof(intmass);
			dval *= sign;

			*va_arg(ap, float*) = dval;
			pstr++;
			break;
		case 'f':
			i = 0;
			if (c == '-') {
				sign = -1;
				c = getchar();
			}
			else if (c == '+') {
				sign = 1;
				c = getchar();
			}
			else sign = 1;
			while (isdigit(c)) {
				intmass[i++] = c;
				c = getchar();
			}
			intmass[i++] = ',';
			if (c == '.' || c == ',') {
				c = getchar();
				while (isdigit(c)) {
					intmass[i++] = c;
					c = getchar();
				}
			}
			else intmass[i++] = 0;
			intmass[i] = '\0';
			dval = atof(intmass) * sign;
			*va_arg(ap, float*) = dval;
			digitflag = AfterD;
			intmass[0] = '\0';
			pstr++;
			break;
		case 'o':
			mul = 1;
			i = 0;
			while (isdigit(c)) {
				intmass[i++] = c;
				c = getchar();
			}
			intmass[i] = '\0';
			while (i-- != 1) {
				mul *= 8;
			}
			i = 0;
			ival = 0;
			while (intmass[i] != '\0') {
				digit = intmass[i++] - '0';
				ival += mul * digit;
				mul /= 8;
			}
			*va_arg(ap, int*) = ival;
			pstr++;
			break;
		case 's':
			i = 0;
			while (c != '\n') {
				strval[i++] = c;
				c = getchar();
			}
			strval[i] = '\0';
			mystrcpy(va_arg(ap, char*), strval);
			strval[0] = '\0';
			pstr++;
			break;
		case 'x':
			mul = 1;
			i = 0;
			while (isdigit(c) || c >= 'a' && c <= 'f' || c >= 'A' && c <= 'F') {
				intmass[i++] = c;
				c = getchar();
			}
			intmass[i] = '\0';
			while (i-- != 1) {
				mul *= 16;
			}
			i = 0;
			ival = 0;
			while (intmass[i] != '\0') {
				switch (intmass[i])
				{
				case 'a':
				case 'A':
					digit = 10;
					break;
				case 'b':
				case 'B':
					digit = 11;
					break;
				case 'c':
				case 'C':
					digit = 12;
					break;
				case 'd':
				case 'D':
					digit = 13;
					break;
				case 'e':
				case 'E':
					digit = 14;
					break;
				case 'f':
				case 'F':
					digit = 15;
					break;
				default:
					digit = intmass[i] - '0';
					break;
				}
				ival += mul * digit;
				i++;
				mul /= 16;
			}
			*va_arg(ap, int*) = ival;
			pstr++;
			break;
		case 'u':
			i = 0;
			while (isdigit(c)) {
				intmass[i++] = c;
				c = getchar();
			}
			intmass[i] = '\0';
			uval = atoi(intmass);
			*va_arg(ap, unsigned int*) = uval;
			digitflag = AfterD;
			intmass[0] = '\0';
			pstr++;
			break;
		case 'n':
			n = 0;
			while (c != '\n') {
				n++;
				c = getchar();
			}
			*va_arg(ap, int*) = n;
			break;
		case '%':
			if (c == '%')
				*va_arg(ap, char*) = '%';
			break;
		}
	}
	va_end(ap);
}