#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, s) \
	if( !( (p) = malloc( s ) ) ){	\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

// Linked Queues
#define MAX_QUEUES 3 
typedef struct {
	int id;				//학번
	int grade;			//성적
	} element;
typedef struct queue *queuePointer;
typedef struct queue {
	element data;
	queuePointer link;
	}Node;
queuePointer front[MAX_QUEUES] ={NULL};
queuePointer rear[MAX_QUEUES] ={NULL};
void addq(int i, element item);
element deleteq(int i);
element queueEmpty();

int main(void)
{
	element student;
	int course, i;
	FILE *fp;	
	
	fopen_s(&fp, "input.txt", "r");
	if(fp  == NULL )
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}
	
	// input
	fscanf_s(fp, "%d%d%d", &course, &student.id, &student.grade);
	while( !feof(fp) )
	{
		addq(course, student);
		fscanf_s(fp, "%d%d%d", &course, &student.id, &student.grade);
	}

	//output
	printf("과목번호, 학번, 성적\n");
	for ( i = 0 ; i < MAX_QUEUES; i++)
	{		
		printf("**********************\n");
		while( front[i] )
		{
			student = deleteq(i);
			printf("%8d%6d%6d\n",  i, student.id, student.grade);
		}
	}
	
	fclose(fp);
	return 0;
}

void addq(int i, element item)
{/* add item to the rear of queue i */
	queuePointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = item;
	temp->link = NULL;

	if(front[i])
		rear[i]->link = temp;
	else
		front[i] = temp;
	
	rear[i] = temp;
}

element deleteq(int i)
{/* delete an element from queue i */
	queuePointer temp = front[i];
	element item;
	
	if(!temp)
		return queueEmpty();
	
	item = temp->data;
	front[i] = temp->link;
	free(temp);
	
	return item;
}

element queueEmpty()
{
	element item;
	item.grade = -1;// error key
	return item;
}
