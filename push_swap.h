#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct Node {
    int data;
	int moves;
	int aind;
	int bind;
    struct Node	*next;
	struct Node *prev;
} Node;

typedef struct Stack {
    Node	*top;
	Node	*bottom;
} Stack;


int max(int a, int b);
int min(int a, int b);
void initStack(Stack *stack);
int isEmpty(Stack* stack);
void push(Stack* stack, int data);
int pop(Stack* stack);
void sa(Stack* a);
void sb(Stack* b);
void ss(Stack* a, Stack* b);
void pa(Stack* a, Stack* b);
void pb(Stack* a, Stack* b);
void ra(Stack* a);
void rb(Stack* b);
void rr(Stack* a, Stack* b);
void rra(Stack* a);
void rrb(Stack* b);
void rrr(Stack* a, Stack* b);
int stacksize(Stack *stack);

#endif