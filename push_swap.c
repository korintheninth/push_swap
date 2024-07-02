#include <bits/types/stack_t.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

#define RA 0
#define RB 1
#define RR 2
#define RRA 3
#define RRB 4
#define RRR 5
#define SA 6
#define SB 7
#define SS 8
#define PA 9
#define PB 10


typedef struct Node {
    int data;
	int moves;
    struct Node	*next;
	struct Node *prev;
} Node;

typedef struct Stack {
    Node	*top;
	Node	*bottom;
} Stack;

int max(int a, int b)
{
	if (a < b)
		return (b);
	else
	 return (a);
}

int min(int a, int b)
{
	if (a > b)
		return (b);
	else
	 return (a);
}

void initStack(Stack *stack)
{
    stack->top = NULL;
	stack->bottom = NULL;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
	if (stack->bottom == NULL)
		stack->bottom = newNode;
	if (stack->top != NULL)
		stack->top->prev = newNode;
    stack->top = newNode;
	stack->top->prev = stack->bottom;
	stack->bottom->next = stack->top;
}

int pop(Stack* stack) {
    Node* temp = stack->top;
    int poppedData = temp->data;
    stack->top = stack->top->next;
	stack->bottom->next = stack->top;
	stack->top->prev = stack->bottom;
    free(temp);
    return poppedData;
}

void sa(Stack* a) {
    if (a->top && a->top->next) {
        int temp = a->top->data;
        a->top->data = a->top->next->data;
        a->top->next->data = temp;
    }
}

void sb(Stack* b) {
    if (b->top && b->top->next) {
        int temp = b->top->data;
        b->top->data = b->top->next->data;
        b->top->next->data = temp;
    }
}

void ss(Stack* a, Stack* b) {
    sa(a);
    sb(b);
}

void pa(Stack* a, Stack* b) {
    if (!isEmpty(b)) {
        push(a, pop(b));
    }
}

void pb(Stack* a, Stack* b) {
    if (!isEmpty(a)) {
        push(b, pop(a));
    }
}

void ra(Stack* a) {
    if (a->top && a->top->next) {
        Node* temp = a->top;
        Node* last = a->top;
        while (last->next) {
            last = last->next;
        }
        a->top = a->top->next;
    }
}

void rb(Stack* b) {
    if (b->top && b->top->next) {
        Node* temp = b->top;
        Node* last = b->top;
        while (last->next) {
            last = last->next;
        }
        b->top = b->top->next;
    }
}

void rr(Stack* a, Stack* b) {
    ra(a);
    rb(b);
}

void rra(Stack* a) {
    if (a->top && a->top->next) {
        Node* temp = a->top;
        Node* prev = NULL;
        while (temp->next) {
            prev = temp;
            temp = temp->next;
        }
        a->top = temp;
    }
}

void rrb(Stack* b) {
    if (b->top && b->top->next) {
        Node* temp = b->top;
        Node* prev = NULL;
        while (temp->next) {
            prev = temp;
            temp = temp->next;
        }
        b->top = temp;
    }
}

void rrr(Stack* a, Stack* b) {
    rra(a);
    rrb(b);
}

size_t stacksize(Stack *stack)
{
	Node *curr;
	size_t size;

	if (stack->top == NULL)
		return (0);
	curr =stack->top;
	size = 0;
	do {
		curr = curr->next;
		size++;
	}while (curr != stack->top);
	return (size);
}

int moves(Stack *a, Stack *b, Node node)
{
	int aind;
	int total;
	int bind;
	Node temp;

	aind = 0;
	temp = node;
	while (temp.data != a->top->data)
	{
		temp = *temp.prev;
		aind++;
	}
	bind = 0;
	temp = *b->top;
	while (!((temp.prev->data > node.data && node.data > temp.data) || (temp.prev->data < temp.data && temp.data < node.data) || (node.data < temp.prev->data && temp.data > temp.prev->data)))
	{
		temp = *temp.next;
		bind++;
	}
	printf("%d %d\n", aind, bind);
	total = max(aind, bind);
	if (total > max(stacksize(a) - aind, stacksize(b) - bind))
		total = max(stacksize(a) - aind, stacksize(b) - bind);
	if (total > bind + stacksize(a) - aind)
		total = bind + stacksize(a) - aind;
	if (total > stacksize(b) - bind + aind)
		total = stacksize(b) - bind + aind;
	return total;
}


void set_movec(Stack *stack_a, Stack *stack_b)
{
	Node *curr;

	curr = stack_a->top;
	do
	{
		curr->moves = moves(stack_a, stack_b, *curr);
		printf("data: %d move: %d\n", curr->data, curr->moves);
		curr = curr->next;
	}while (curr != stack_a->top);
	printf("\n");
	curr = stack_b->top;
	do
	{
		printf("curr: %d\n", curr->data);
		curr = curr->next;
	}while (curr != stack_b->top);
}

int *moveset(Stack *a, Stack *b)
{
	Node *curr;
	Node *node;
	int aind;
	int bind;
	int *ret;
	int i;

	node = a->top;
	curr = a->top;
	do
	{
		if (curr->moves < node->moves)
			node = curr;
		curr = curr->next;
	}while (curr != a->top);


	aind = 0;
	curr = node;
	while (curr->data != a->top->data)
	{
		curr = curr->prev;
		aind++;
	}
	bind = 0;
	curr = b->top;
	while (!((curr->prev->data > node->data && node->data > curr->data) || (curr->prev->data < curr->data && curr->data < node->data) || (node->data < curr->prev->data && curr->data > curr->prev->data)))
	{
		curr = curr->next;
		bind++;
	}
	i = 0;
	printf("%d %d\n", aind, bind);
	ret = malloc((node->moves + 1) * sizeof(int));
	if (node->moves ==  max(aind, bind))
	{
		while (i < min(aind, bind))
			ret[i++] = 0;
		if (min(aind, bind) == aind)
			while (i < node->moves)
				ret[i++] = 1;
		else
			while (i < node->moves)
				ret[i++] = 2;
	}	
	else if (node->moves == max(stacksize(a) - aind, stacksize(b) - bind))
	{
		while (i < min(stacksize(a) - aind, stacksize(b) - bind))
			ret[i++] = 3;
		if (min(stacksize(a) - aind, stacksize(b) - bind) == aind)
			while (i < node->moves)
				ret[i++] = 4;
		else
			while (i < node->moves)
				ret[i++] = 5;
	}	
	else if (node->moves == bind + stacksize(a) - aind)
	{
		while (i < bind)
			ret[i++] = 6;
		while (i < node->moves)
			ret[i++] = 7;
	}
	else if (node->moves == stacksize(b) - bind + aind)
	{
		while (i < aind)
			ret[i++] = 8;
		while (i < node->moves)
			ret[i++] = 9;
	}
	return (ret);
}

int main(int argc, char **argv)
{
	Stack *stack_a;
	Stack *stack_b;

	stack_a = malloc(sizeof(Stack));
	stack_b = malloc(sizeof(Stack));
	initStack(stack_a);
	initStack(stack_b);
	if (argc > 1)
		while (argc - 1 > 0)
			push(stack_a, ft_atoi(argv[(argc--) - 1]));
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	if (stack_b->top->data < stack_b->top->next->data)
		sb(stack_b);
	set_movec(stack_a, stack_b);
}
