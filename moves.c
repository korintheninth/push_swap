#include "push_swap.h"

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
	if (stacksize(stack) > 1)
	{
  		stack->top = stack->top->next;
		stack->bottom->next = stack->top;
		stack->top->prev = stack->bottom;
	}
	else
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
    free(temp);
    return poppedData;
}

void sa(Stack* a) {
    if (a->top && a->top->next) {
        int temp = a->top->data;
        a->top->data = a->top->next->data;
        a->top->next->data = temp;
    }
	write(1, "sa\n", 3);
}

void sb(Stack* b) {
    if (b->top && b->top->next) {
        int temp = b->top->data;
        b->top->data = b->top->next->data;
        b->top->next->data = temp;
    }
	write(1, "sb\n", 3);
}

void ss(Stack* a, Stack* b) {
    if (a->top && a->top->next) {
        int temp = a->top->data;
        a->top->data = a->top->next->data;
        a->top->next->data = temp;
    }
    if (b->top && b->top->next) {
        int temp = b->top->data;
        b->top->data = b->top->next->data;
        b->top->next->data = temp;
    }
	write(1, "ss\n", 3);
}

void pa(Stack* a, Stack* b) {
    if (!isEmpty(b)) {
        push(a, pop(b));
    }
	write(1, "pa\n", 3);
}

void pb(Stack* a, Stack* b) {
    if (!isEmpty(a)) {
        push(b, pop(a));
    }
	write(1, "pb\n", 3);
}

void ra(Stack* a) {
    if (a->top && a->top->next) {
		a->top = a->top->next;
		a->bottom = a->bottom->next;
    }
	write(1, "ra\n", 3);
}

void rb(Stack* b) {
    if (b->top && b->top->next) {
		b->top = b->top->next;
		b->bottom = b->bottom->next;
    }
	write(1, "rb\n", 3);
}

void rr(Stack* a, Stack* b) {
    if (a->top && a->top->next) {
		a->top = a->top->next;
		a->bottom = a->bottom->next;
    }
    if (b->top && b->top->next) {
		b->top = b->top->next;
		b->bottom = b->bottom->next;
    }
	write(1, "rr\n", 3);
}

void rra(Stack* a) {
    if (a->top && a->top->next) {
		a->top = a->top->prev;
		a->bottom = a->bottom->prev;
    }
	write(1,"rra\n", 4);
}

void rrb(Stack* b) {
    if (b->top && b->top->next) {
		b->top = b->top->prev;
		b->bottom = b->bottom->prev;
    }
	write(1,"rrb\n", 4);
}

void rrr(Stack* a, Stack* b) {
    if (a->top && a->top->next) {
		a->top = a->top->prev;
		a->bottom = a->bottom->prev;
    }
    if (b->top && b->top->next) {
		b->top = b->top->prev;
		b->bottom = b->bottom->prev;
    }
	write(1,"rrr\n", 4);
}

int stacksize(Stack *stack)
{
	Node *curr;
	int size;

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