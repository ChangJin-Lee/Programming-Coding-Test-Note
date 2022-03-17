#include <stdio.h>
#include <stdlib.h>

// ����ü ����
struct person
{
	char name[9];	// �̸�
	char gender[3];	// ����
	int age;		// ����
};

int main()
{
	FILE *fp;
	char c;
	// �� ���� ����� ������ ����ü ������ �����ϱ�
	struct person u1, u2, u3; 
	struct person oldest; // �ְ������ ������ ������ ����ü ����

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
		// u1�� u3 �� ����� ã��
		if (u1.age > u3.age)
			oldest = u1;	// u1�� ��� ����� oldest ����ü ������ �� ���� �����Ѵ�.
		else
			oldest = u3;
	}
	else
	{
		// u2�� u3 �� ����� ã��
		if (u2.age > u3.age)
			oldest = u2;
		else
			oldest = u3;
	}

	printf(" �̸�   ����	���� \n");
	printf("======================\n");
	printf("%s\t %s\t %2d\n", u1.name, u1.gender, u1.age);
	printf("%s\t %s\t %2d\n", u2.name, u2.gender, u2.age);
	printf("%s\t %s\t %2d\n", u3.name, u3.gender, u3.age);
	printf("======================\n\n");
	printf(" << �ְ�� ����� >>\n\n");
	printf(" %s\t %s\t %d\n\n", oldest.name, oldest.gender, oldest.age);

	fclose(fp);
	return 0;
}