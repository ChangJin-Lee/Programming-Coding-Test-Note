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
// 초기화 함수
void init(QueueType *q)
{
	q->front = q->rear = 0;
}
// 공백 상태 검출 함수
int is_empty(QueueType *q)
{
	return (q->front == q->rear);
}
// 포화 상태 검출 함수
int is_full(QueueType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
// 삽입 함수
void enqueue(QueueType *q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}
// 삭제 함수
element dequeue(QueueType *q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}
// 삭제 함수
element peek(QueueType *q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}


void radix_sort(int list[], int n)
{
	int i, b, d, factor = 1;
	QueueType queues[BUCKETS];

	for (d = 0; d<DIGITS; d++) {
		for (b = 0; b<BUCKETS; b++) init(&queues[b]);  // 큐들의 초기화
		printf("\nstep %d 자리  --- \n", d);
		printf("\nQueue의 내용  --- \n");
		for (i = 0; i < n; i++)
			printf("%5d", i);
		printf("\n");

		for (i = 0; i<n; i++)			// 데이터들을 자리수에 따라 큐에 삽입
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

		for (b = i = 0; b<BUCKETS; b++)  // 버킷에서 꺼내어 list로 합친다.
			while (!is_empty(&queues[b]))
				list[i++] = dequeue(&queues[b]);
		factor *= 10;					// 그 다음 자리수로 간다.


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

