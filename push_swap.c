#include "push_swap.h"

void	rota(Stack *a, int b)
{
	Node *temp;
	int ind;

	ind = 0;
	temp = a->top;
	while (!((temp->prev->data < b && b < temp->data) || (temp->prev->data > temp->data && temp->data > b) || (b > temp->prev->data && temp->data < temp->prev->data)))
	{
		temp = temp->next;
		ind++;
	}
	if (ind < stacksize(a) - ind)
		while (ind--)
			ra(a);
	else
		while (stacksize(a) - ind++)
			rra(a);
}

void	push_back(Stack *a, Stack *b)
{
	while (stacksize(b))
	{
		rota(a, b->top->data);
		pa(a, b);
	}
}

void	solve_for3(Stack *a)
{
	if (a->top->data < a->top->next->data && a->top->data > a->bottom->data)
		rra(a);
	else if (a->top->data > a->top->next->data && a->bottom->data > a->top->data)
		sa(a);
	else if (a->top->data < a->top->next->data && a->top->next->data > a->bottom->data)
	{
		ra(a);
		sa(a);
		rra(a);
	}
	else if (a->top->data > a->top->next->data && a->bottom->data < a->bottom->prev->data)
	{
		sa(a);
		rra(a);
	}
	else if(a->top->data > a->top->next->data && a->bottom->data > a->bottom->prev->data)
		ra(a);
}

void moves(Stack *a, Stack *b, Node *node)
{
	int aind;
	int total;
	int bind;
	Node *temp;

	aind = 0;
	temp = node;
	while (temp != a->top)
	{
		temp = temp->prev;
		aind++;
	}
	bind = 0;
	temp = b->top;
	while (!((temp->prev->data > node->data && node->data > temp->data) || (temp->prev->data < temp->data && temp->data < node->data) || (node->data < temp->prev->data && temp->data > temp->prev->data)))
	{
		temp = temp->next;
		bind++;
	}
	node->aind = aind;
	node->bind = bind;
	total = max(aind, bind);
	if (total > max(stacksize(a) - aind, stacksize(b) - bind))
		total = max(stacksize(a) - aind, stacksize(b) - bind);
	if (total > bind + stacksize(a) - aind)
		total = bind + stacksize(a) - aind;
	if (total > stacksize(b) - bind + aind)
		total = stacksize(b) - bind + aind;
	node->moves = total;
}



void set_movec(Stack *stack_a, Stack *stack_b)
{
	Node *curr;

	curr = stack_a->top;
	do
	{
		moves(stack_a, stack_b, curr);
		curr = curr->next;
	}while (curr != stack_a->top);
}

int	min_move(Stack *a)
{
	int min;
	Node *temp;
	
	min = a->top->data;
	temp = a->top;
	do
	{
		if (min > temp->data)
			min = temp->data;
		temp = temp->next;
	}while(temp != a->top);
	return (min);
}

void	apply(Stack *a, Stack *b)
{
	Node *temp;
	int i;

	temp = a->top;
	while (temp->data != min_move(a))
		temp = temp->next;
	i = 0;
	if(temp->moves == max(temp->aind, temp->bind))
	{
		while (i < min(temp->aind, temp->bind))
		{
			rr(a, b);
			i++;
		}
		if (temp->aind > temp->bind)
			while (i < temp->moves)
			{
				ra(a);
				i++;
			}
		else
			while (i < temp->moves)
			{
				rb(b);
				i++;
			}
	}
	else if (temp->moves == max(stacksize(a) - temp->aind, stacksize(b) - temp->bind))
	{
		while (i < min(stacksize(a) - temp->aind, stacksize(b) -  temp->bind))
		{
			rrr(a, b);
			i++;
		}
		if (stacksize(a) - temp->aind > stacksize(b) - temp->bind)
			while (i < temp->moves)
			{
				rra(a);
				i++;
			}
		else
			while (i < temp->moves)
			{
				rrb(b);
				i++;
			}
	}
	else if (temp->moves == temp->bind + stacksize(a) - temp->aind)
	{
		while (i < stacksize(a) - temp->aind)
		{
			rra(a);
			i++;
		}
		while (i < temp->moves)
		{
			rb(b);
			i++;
		}
	}
	else if (temp->moves == stacksize(b) - temp->bind + temp->aind)
	{
		while (i < temp->aind)
		{
			ra(a);
			i++;
		}
		while (i < temp->moves)
		{
			rrb(b);
			i++;
		}
	}
	pb(a, b);
}

void	solve(Stack *a, Stack *b)
{	
	while(stacksize(a) > 3)
	{
		set_movec(a, b);
		apply(a, b);
	}
	solve_for3(a);
	push_back(a, b);
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
	solve(stack_a, stack_b);
}
