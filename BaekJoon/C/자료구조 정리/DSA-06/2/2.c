#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
#define MAX_ROW_SIZE 10
#define MAX_COL_SIZE 10
#define TRUE 1
#define FALSE 0

// maze search
int maze[MAX_ROW_SIZE + 2][MAX_COL_SIZE + 2];
int mark[MAX_ROW_SIZE + 2][MAX_COL_SIZE + 2] = { 0 };
typedef struct {
	short int vert;
	short int horiz;
} offsets;
offsets move[8] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
int EXIT_ROW;
int EXIT_COL;

void path(void);

// stack for maze search
typedef struct {
	short int row;
	short int col;
	short int dir;
}element;
element stack[MAX_STACK_SIZE];
int top = -1;
void push(element item);
void stackFull();
element pop();
element stackEmpty();

int main(void)
{
	int r, c;
	int nRows, nCols;
	FILE *fp;	

	fopen_s(&fp, "input.txt", "r");
	if(fp == NULL )
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}
	
	fscanf_s(fp, "%d%d", &nRows, &nCols);
	for ( r = 0; r <= nRows+1; r++ )
	{
		for ( c = 0; c <= nCols+1; c++ )
		{
			if ( r == 0 || r == nRows+1 || c == 0 || c == nCols+1 )
				maze[r][c] = 1;
			else
				fscanf_s( fp, "%d", &maze[r][c] );
		}
	}

/*
	for (r = 0; r <= nRows + 1; r++) {
		for (c = 0; c <= nCols + 1; c++) 
			printf("%d", maze[r][c]);
		printf("\n");
		}
*/

	EXIT_ROW = nRows;
	EXIT_COL = nCols;

	path();
	
	return 0;
}

void path(void)
{
	/*output a path through the maze if such a path exists */
	int i, row, col, nextRow, nextCol, dir, found = FALSE;
	element position;
	mark[1][1] = 1; top = 0;
	stack[0].row = 1; stack[0].col = 1; stack[0].dir = 1;

	while( top > -1 && !found)
	{
		position = pop();
		row = position.row;  col = position.col; 
		dir = position.dir;

		while( dir < 8 && !found )
		{ /* move n direction dir */
			nextRow = row + move[dir].vert;
			nextCol = col + move[dir].horiz;

			if( nextRow == EXIT_ROW && nextCol == EXIT_COL )
				found = TRUE;
			else if( !maze[nextRow][nextCol] && !mark[nextRow][nextCol])	
			{
				mark[nextRow][nextCol] = 1;
				position.row = row;		position.col = col;
				position.dir = ++dir;
				push(position);
				row = nextRow; col = nextCol; dir = 0;
			}else ++dir;
		}//while
	}//while

	if(found)
	{
		printf("The path is: \n");
		printf("row col\n");
		for( i = 0; i <= top; i++)
			printf("%2d%5d\n", stack[i].row, stack[i].col);
		printf("%2d%5d\n", row, col);
		printf("%2d%5d\n", EXIT_ROW, EXIT_COL);
	}
	else 
		printf("The maze does not have a path\n");
}

/////////////////////// stack operations ///////////////////////////////////
element pop()
{/* delete and return the top element from the stack */
	if ( top == -1 )
		return stackEmpty();	/* returns an error key */
	return stack[top--];
}

element stackEmpty()
{
	element item;
	item.row = -1;  // error key value
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
		printf("%d %d %d\n", item.row, item.col, item.dir);
	}

	exit(EXIT_FAILURE);
}
