#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, s) \
	if( !( (p) = malloc( s ) ) ){	\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

// Linked Stacks
#define MAX_STACKS 3 
typedef struct {
	int id;				//�й�
	int grade;			//����
	} element;
typedef struct stack *stackPointer;
typedef struct stack {
	element data;
	stackPointer link;
	};
stackPointer top[MAX_STACKS] = {NULL};
void push(int i, element item);
element pop(int i);
element stackEmpty();

int main(void)
{
	element student;
	int course, i;
	FILE *fp;	
	
	fopen_s(&fp, "input.txt", "r");
	if(fp == NULL )	
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}
	
	// input
	fscanf_s(fp, "%d%d%d", &course, &student.id, &student.grade);
	while( !feof(fp) )
	{
		push(course, student);
		fscanf_s(fp, "%d%d%d", &course, &student.id, &student.grade);
	}

	//output
	printf("�����ȣ, �й�, ����\n");
	for ( i = 0 ; i < MAX_STACKS; i++)
	{		
		printf("**********************\n");
		while( top[i] )
		{
			student = pop(i);
			printf("%8d%6d%6d\n",  i, student.id, student.grade);
		}
	}

	fclose(fp);
	return 0;
}

void push(int i, element item)
{/* add item to the ith stack */
	stackPointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = item;
	temp->link = top[i];
	top[i] = temp;
}

element pop(int i)
{/* remove top element from the ith stack */
	stackPointer temp = top[i];
	element item;
	
	if( !temp)
		return stackEmpty();
	
	item = temp->data;
	top[i] = temp->link;
	free(temp);
	return item;
}

element stackEmpty()
{
	element item;
	item.grade = -1 ; // error key
	return item;
}
