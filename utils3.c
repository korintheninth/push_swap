/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:15:20 by emamati           #+#    #+#             */
/*   Updated: 2024/07/04 16:21:45 by emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rota(t_stack *a, int b)
{
	t_node	*temp;
	int		ind;

	ind = 0;
	temp = a->top;
	while (!((temp->prev->data < b && b < temp->data)
			|| (temp->prev->data > temp->data && temp->data > b)
			|| (b > temp->prev->data && temp->data < temp->prev->data)))
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

void	push_back(t_stack *a, t_stack *b)
{
	while (stacksize(b))
	{
		rota(a, b->top->data);
		pa(a, b);
	}
}

void	solve_for3(t_stack *a)
{
	if (a->top->data < a->top->next->data && a->top->data > a->bottom->data)
		rra(a);
	else if (a->top->data > a->top->next->data
		&& a->bottom->data > a->top->data)
		sa(a);
	else if (a->top->data < a->top->next->data
		&& a->top->next->data > a->bottom->data)
	{
		ra(a);
		sa(a);
		rra(a);
	}
	else if (a->top->data > a->top->next->data
		&& a->bottom->data < a->bottom->prev->data)
	{
		sa(a);
		rra(a);
	}
	else if (a->top->data > a->top->next->data
		&& a->bottom->data > a->bottom->prev->data)
		ra(a);
}

void	set_movec(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*curr;

	curr = stack_a->top;
	moves(stack_a, stack_b, curr);
	curr = curr->next;
	while (curr != stack_a->top)
	{
		moves(stack_a, stack_b, curr);
		curr = curr->next;
	}
}

int	min_move(t_stack *a)
{
	int		min;
	t_node	*temp;

	min = a->top->moves;
	temp = a->top->next;
	while (temp != a->top)
	{
		if (min > temp->moves)
			min = temp->moves;
		temp = temp->next;
	}
	return (min);
}
