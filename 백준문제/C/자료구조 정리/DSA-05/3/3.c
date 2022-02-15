//  circular queue
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 3
#define MAX_NAME_SIZE 20

typedef struct {
	int id;												// unique id
	char name[MAX_NAME_SIZE];	// last name
}element;
element Que[MAX_QUEUE_SIZE];
element *queue;

int rear, front;

void qprint()
{
	int i;
	i = front;
	for (; i != rear;) {
		i = (i + 1) % MAX_QUEUE_SIZE;
		printf("%d, %s\n", queue[i].id, queue[i].name);
	}
	printf("\n");
}

void qinitialize()
{
	front = rear = 0;
}

int isEmpty()
{
	return (front == rear);
}

int isFull()
{
	return ((rear + 1) % MAX_QUEUE_SIZE == front);
}

void addq(element item)
{
	if (isFull()) {
		printf("queue is full, not added\n");
		return;
	}
	rear++;
	rear = rear % MAX_QUEUE_SIZE;
	queue[rear] = item;
}

element deleteq()
{
	if (isEmpty()) {
		printf("queue is empty\n");
	}
	front = (front + 1) % MAX_QUEUE_SIZE;
	return queue[front];
}

int queue_count()
{
	if (rear > front) return rear - front;
	else return rear + MAX_QUEUE_SIZE - front;
}
void main()
{
	char input[80];				// input a line of string
	char *delimiter = " \n";	// delimiter for tokenizing
	char *context;
	char *op = NULL;			// addq or deleteq
	element student;

	queue = Que;

	qinitialize();
	printf("<< Circular queue operations where MAX_QUEUE_SIZE is %d>>\n", MAX_QUEUE_SIZE);
	printf("add 1 Jung\n");
	printf("delete\n\n");
	printf("**************************************************\n");

	while (1)
	{
		gets_s(input, sizeof(input));
		op = strtok_s(input, delimiter, &context);

		if (!strcmp(op, "add")) // addq
		{
			sscanf_s(input + strlen(op) + 1, "%d%s", &student.id, student.name, (unsigned int)sizeof(student.name));
			addq(student);
		}
		else if (!strcmp(op, "delete")) // deleteq
		{
			element item;
			item = deleteq();
			if (item.id == -1)
			{
				fprintf(stderr, "queue is empty, cannot delete element.\n");
				exit(EXIT_FAILURE);
			}
		}
		else if (!strcmp(op, "qprint"))
			qprint();
		else if (!strcmp(op, "quit"))
			break;
		else
			printf("wrong command! try again!\n");
	}// while

}