/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:44:51 by emamati           #+#    #+#             */
/*   Updated: 2024/07/04 15:50:37 by emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	temp;

	if (a->top && a->top->next)
	{
		temp = a->top->data;
		a->top->data = a->top->next->data;
		a->top->next->data = temp;
	}
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	int	temp;

	if (b->top && b->top->next)
	{
		temp = b->top->data;
		b->top->data = b->top->next->data;
		b->top->next->data = temp;
	}
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	int	temp;

	if (a->top && a->top->next)
	{
		temp = a->top->data;
		a->top->data = a->top->next->data;
		a->top->next->data = temp;
	}
	if (b->top && b->top->next)
	{
		temp = b->top->data;
		b->top->data = b->top->next->data;
		b->top->next->data = temp;
	}
	write(1, "ss\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	if (!isempty(b))
	{
		push(a, pop(b));
	}
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	if (!isempty(a))
	{
		push(b, pop(a));
	}
	write(1, "pb\n", 3);
}
