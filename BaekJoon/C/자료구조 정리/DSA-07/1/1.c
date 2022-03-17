//  stack - evaluation of postfix expression
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_EXPR_LEN 80

// eval
typedef enum { lparen, rparen, plus, minus, times, divide, 
							mod, eos, operand } precedence;
int eval(void);
precedence getToken(char *symbol, int *n);

// stack 
int stack[MAX_STACK_SIZE];
int top = -1;
void push(int item);
void stackFull();
int pop();
int stackEmpty();

// postfix expression 
char expr[MAX_EXPR_LEN];

int main(void)
{
	int result;
	FILE *fp, *fpP;	

	fopen_s(&fp, "input.txt", "r");
	fopen_s(&fpP, "output.txt", "w");
	if(!fp )
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}

	fgets(expr, MAX_EXPR_LEN, fp);
	printf("postfix expression : %s\n", expr);
	fprintf(fpP, "postfix expression : %s\n", expr);
	printf("the evaluation value : %d\n", eval());
	fprintf(fpP, "the evaluation value : %d\n", eval());
	fclose(fpP);

	return 0;
}

int eval(void)
{
	precedence token;
	char symbol;
	int op1, op2;
	int n = 0; /* counter for the expression string */
	top = -1;
	token = getToken(&symbol, &n);
	while( token != eos )
	{
		if( token == operand )
			push(symbol -'0'); /* stack insert */
		else{
			/* pop two operands, perform operation, and 
			push result to the stack */
			op2 = pop();	/* stack delete */
			op1 = pop();
			switch(token) {
				case plus:		push (op1 + op2);
									break;
				case minus:	push(op1 - op2);
									break;
				case times:	push(op1 * op2);
									break;
				case divide:	push( op1 / op2 );
									break;
				case mod:	push(op1 % op2);
			}
		}
		token = getToken( &symbol, &n);
	}
	return pop(); /* return result */
}

// Program 3.14: Function to get a token from the input string
precedence getToken(char *symbol, int *n)
{ /* get the next token, symbol is the character representation, 
	whichis returned, the tokenis represented by its enumerated value, 
	which is returned inthe function name */
	*symbol = expr[ (*n)++ ];
	switch ( *symbol) 
	{
			case '('		: return lparen;
			case ')'		:  return rparen;
			case '+'		: return plus;
			case '-'		: return minus;
			case '/'		: return divide;
			case '*'		: return times;
			case '%'	: return mod;
			case '\0'	: return eos;
			default		: return operand; /* no error checking, default is operand */
	}
}

/////////////////////// stack operations ///////////////////////////////////
int pop()
{/* delete and return the top int from the stack */
	if ( top == -1 )
		return stackEmpty();	/* returns an error key */
	return stack[top--];
}

int stackEmpty()
{
	int item;
	item = -1;  // error key value
	return item;
}

void push(int item)
{/* add an item to the global stack */
	if ( top >= MAX_STACK_SIZE-1 )
		stackFull();
	stack[++top] = item;
}

void stackFull()
{
	int item;
	fprintf(stderr, "stack is full, cannot add int\n");
	exit(EXIT_FAILURE);
}
