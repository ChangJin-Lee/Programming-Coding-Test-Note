#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

typedef enum{
	False,
	True
}bool;

bool Checkstr(char str[]) {
	bool check = False;
	int strlength = strlen(str);
	for (int i = 0; i < strlength - 1; i++) {
		//strcat(str[i], str[i + 1]);
		if ((str[i] == 'D' || str[i] == 'd') && str[i + 1] == '2') {
			check = True;
		}
	}
	return check;
}

int main() {
	char strings[10000];
	gets(strings);
	if (Checkstr(strings)) printf("D2");
	else printf("unrated");
}

