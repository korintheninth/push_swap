/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:18:37 by emamati           #+#    #+#             */
/*   Updated: 2024/07/04 17:28:28 by emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_minind(t_stack *a)
{
	int		ind;
	int		minind;
	t_node	*min;
	t_node	*curr;

	ind = 1;
	minind = 0;
	curr = a->top->next;
	min = a->top;
	while (curr != a->top)
	{
		if (curr->data < min->data)
		{
			min = curr;
			minind = ind;
		}
		curr = curr->next;
		ind++;
	}
	return (minind);
}

void	final_rot(t_stack *a)
{
	int	minind;

	minind = get_minind(a);
	if (minind < (stacksize(a) - minind))
	{
		while (minind--)
			ra(a);
	}
	else
	{
		while (stacksize(a) - minind++)
			rra(a);
	}
}

void	solve(t_stack *a, t_stack *b)
{
	if (stacksize(a) >= 5)
	{
		pb(a, b);
		pb(a, b);
		if (b->top->data < b->bottom->data)
			sb(b);
	}
	if (stacksize(a) == 4)
		pb(a, b);
	while (stacksize(a) > 3)
	{
		set_movec(a, b);
		apply(a, b);
	}
	solve_for3(a);
	push_back(a, b);
	final_rot(a);
}

int	get_moves(int aind, int bind, t_stack *a, t_stack *b)
{
	int	total;

	total = max(aind, bind);
	if (total > max(stacksize(a) - aind, stacksize(b) - bind))
		total = max(stacksize(a) - aind, stacksize(b) - bind);
	if (total > bind + stacksize(a) - aind)
		total = bind + stacksize(a) - aind;
	if (total > stacksize(b) - bind + aind)
		total = stacksize(b) - bind + aind;
	return (total);
}

void	moves(t_stack *a, t_stack *b, t_node *node)
{
	int		aind;
	int		bind;
	t_node	*temp;

	aind = 0;
	temp = node;
	while (temp != a->top)
	{
		temp = temp->prev;
		aind++;
	}
	bind = 0;
	temp = b->top;
	while (!((temp->prev->data > node->data && node->data > temp->data)
			|| (temp->prev->data < temp->data && temp->data < node->data)
			|| (node->data < temp->prev->data
				&& temp->data > temp->prev->data)))
	{
		temp = temp->next;
		bind++;
	}
	node->aind = aind;
	node->bind = bind;
	node->moves = get_moves(aind, bind, a, b);
}
