#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
#define M_DATA 100
#define BUCKETS 10
#define DIGITS  3
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	element  queue[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;
//
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// �ʱ�ȭ �Լ�
void init(QueueType *q)
{
	q->front = q->rear = 0;
}
// ���� ���� ���� �Լ�
int is_empty(QueueType *q)
{
	return (q->front == q->rear);
}
// ��ȭ ���� ���� �Լ�
int is_full(QueueType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
// ���� �Լ�
void enqueue(QueueType *q, element item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}
// ���� �Լ�
element dequeue(QueueType *q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}
// ���� �Լ�
element peek(QueueType *q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}


void radix_sort(int list[], int n)
{
	int i, b, d, factor = 1;
	QueueType queues[BUCKETS];

	for (d = 0; d<DIGITS; d++) {
		for (b = 0; b<BUCKETS; b++) init(&queues[b]);  // ť���� �ʱ�ȭ
		printf("\nstep %d �ڸ�  --- \n", d);
		printf("\nQueue�� ����  --- \n");
		for (i = 0; i < n; i++)
			printf("%5d", i);
		printf("\n");

		for (i = 0; i<n; i++)			// �����͵��� �ڸ����� ���� ť�� ����
			enqueue(&queues[(list[i] / factor) % 10], list[i]);

		for (i = 4; i > 0; i--) {
			for (b = 0; b < BUCKETS; b++)
				if (queues[b].rear >= i)
					printf("%5d", queues[b].queue[i]);
				else 
					printf("     ");
			printf("\n\n");
		}
		printf("---------------------------------------------------\n");

		for (b = i = 0; b<BUCKETS; b++)  // ��Ŷ���� ������ list�� ��ģ��.
			while (!is_empty(&queues[b]))
				list[i++] = dequeue(&queues[b]);
		factor *= 10;					// �� ���� �ڸ����� ����.


		for (i = 0; i<n; i++)
			printf("%5d", list[i]);
		printf("\n");
	}

}
//
void main()
{
	int i, d, n;
	int list[M_DATA];

	FILE *fp;

	if (fopen_s(&fp, "input.txt", "r"))
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}

	fscanf_s(fp, "%d%d", &d, &n);
	for (i = 0; i < n; i++)
		fscanf_s(fp, "%d", &list[i]);

	printf("input data --- \n");
	for (i = 0; i<n; i++)
		printf("%5d", list[i]);
	printf("\n");

	radix_sort(list, n);

	printf("\nresult --- \n");
	for (i = 0; i<n; i++)
		printf("%5d", list[i]);
	printf("\n");
}

