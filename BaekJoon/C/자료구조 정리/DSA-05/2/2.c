//  Linear queue, Array shift
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 3
#define MAX_NAME_SIZE 20

typedef struct {
	int id;												// unique id
	char name[MAX_NAME_SIZE];	// last name
}element;
element queue[MAX_QUEUE_SIZE];
int rear, front;


void qprint()
{
	int i;
	i = front;
	for (; i != rear;) {
		i = i + 1;
		printf("%d %s\n", queue[i].id, queue[i].name);
	}
	printf("\n");
}

void qinitialize()
{
	front = rear = -1;
}

int queueEmpty()
{
	return (front == rear);
}

int isFull()
{
	int temp, i = 0;
	
	if ((rear == MAX_QUEUE_SIZE-1) && (front < 0) )
		return 1;
	if ((rear == MAX_QUEUE_SIZE-1) && (front >= 0)) {
		rear = rear - front-1;
		temp = front + 1;
		while (i <= rear)
			queue[i++] = queue[temp++];	
		front = -1;
		printf("data shift\n");
	}
	
	return 0;
}

void addq(element item)
{
	if (isFull()) {
		printf("queue is full, not added\n");
		return;
	}
	rear++;
	queue[rear] = item;
}

element deleteq()
{
	if (queueEmpty()) {
		fprintf(stderr, "queue is empty, cannot delete element.\n");
		exit(EXIT_FAILURE);
	}
	else {
		front = front + 1;
		return queue[front];
	}
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
			sscanf_s(input + strlen(op) + 1, "%d%s", &student.id, student.name, (int)sizeof(student.name));
			addq(student);
		}
		else if (!strcmp(op, "delete")) // deleteq
			deleteq();
		else if (!strcmp(op, "qprint"))
			qprint();
		else if (!strcmp(op, "quit"))
			break;
		else
			printf("wrong command! try again!\n");
	}// while

}