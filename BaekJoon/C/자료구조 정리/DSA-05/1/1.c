#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 5
#define MAX_NAME_SIZE 20

typedef struct {
	int id;												// unique id
	char name[MAX_NAME_SIZE];	// last name
}element;
element stack[MAX_STACK_SIZE];
int top = -1;

void push(element item);
void stackFull();
element pop();
element stackEmpty();
void sprint();

int main(void)
{
	char input[80];				// input a line of string
	char *delimiter = " \n";	// delimiter for tokenizing
	char *context;
	char *op = NULL;			// push or pop
	element student;	
	int cnt;

	printf("<< stack operations where MAX_STACK_SIZE is %d>>\n", MAX_STACK_SIZE);
	printf("The format of the stack operation is as follows!!\n");
	printf("push 1 Jung\n");
	printf("pop\n\n");
	printf("**************************************************\n");

	while (1)
	{
		gets_s(input, sizeof(input));
		op = strtok_s(input, delimiter, &context);
		if (!strcmp(op, "push"))
		{
			sscanf_s(input + strlen(op) + 1, "%d%s", &student.id, student.name, sizeof(student.name));
			push(student);
		}
		else if (!strcmp(op, "pop"))
		{
			element item;
			item = pop();
			if (item.id == -1)
			{
				fprintf(stderr, "stack is empty, cannot delete element.\n");
				exit(EXIT_FAILURE);
			}
		}
		else if (!strcmp(op, "sprint")) {
			sprint();
			printf("\n");
		}
		else if( !strcmp(op, "quit"))
			break;
		else if (!strcmp(op, "sprint"))
			for(cnt=top; cnt>= 0; cnt--)
				printf("%d %s\n", stack[cnt].id, stack[cnt].name);
		else
			printf("wrong command! try again!\n");

	}// while
		
	return 0;
}


element pop()
{/* delete and return the top element from the stack */
	if ( top == -1 )
		return stackEmpty();	/* returns an error key */
	return stack[top--];
}

element stackEmpty()
{
	element item;
	item.id = -1;  // error key value
	return item;
}

void push(element item)
{/* add an item to the global stack */
	if ( top >= MAX_STACK_SIZE-1 )
		stackFull();
	stack[++top] = item;
}

void stackFull()
{
	element item;
	fprintf(stderr, "stack is full, cannot add element\n");
	
	printf("current stack elements : \n");	
	while( top > -1 )
	{
		item = pop();
		printf("%d %s\n", item.id, item.name);
	}

	exit(EXIT_FAILURE);
}

void sprint()
{
	element item;
	int sp;
	for (sp = top; sp > -1; sp--) 
	{
		item = stack[sp];
		printf("%d %s\n", item.id, item.name);
	}
}