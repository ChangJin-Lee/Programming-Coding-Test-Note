#include <stdio.h>
#include <stdlib.h>

// 구조체 정의
struct person
{
	char name[9];	// 이름
	char gender[3];	// 성별
	int age;		// 나이
};

int main()
{
	FILE *fp;
	char c;
	// 세 명의 사용자 정보를 구조체 변수에 저장하기
	struct person u1, u2, u3; 
	struct person oldest; // 최고령자의 정보를 저장할 구조체 변수

	fopen_s(&fp, "input.txt", "r");
	if (fp == NULL)
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}

	fscanf_s(fp, "%s%s%d", &u1.name, sizeof(u1.name), &u1.gender, sizeof(u1.gender), &u1.age);
	fscanf_s(fp, "%s%s%d", &u2.name, sizeof(u2.name), &u2.gender, sizeof(u2.gender), &u2.age);
	fscanf_s(fp, "%s%s%d", &u3.name, sizeof(u3.name), &u3.gender, sizeof(u3.gender), &u3.age);

	if (u1.age > u2.age)
	{
		// u1과 u3 중 고령자 찾기
		if (u1.age > u3.age)
			oldest = u1;	// u1의 모든 멤버를 oldest 구조체 변수에 한 번에 저장한다.
		else
			oldest = u3;
	}
	else
	{
		// u2와 u3 중 고령자 찾기
		if (u2.age > u3.age)
			oldest = u2;
		else
			oldest = u3;
	}

	printf(" 이름   성별	나이 \n");
	printf("======================\n");
	printf("%s\t %s\t %2d\n", u1.name, u1.gender, u1.age);
	printf("%s\t %s\t %2d\n", u2.name, u2.gender, u2.age);
	printf("%s\t %s\t %2d\n", u3.name, u3.gender, u3.age);
	printf("======================\n\n");
	printf(" << 최고령 사용자 >>\n\n");
	printf(" %s\t %s\t %d\n\n", oldest.name, oldest.gender, oldest.age);

	fclose(fp);
	return 0;
}