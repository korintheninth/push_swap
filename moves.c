/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:41:36 by emamati           #+#    #+#             */
/*   Updated: 2024/07/04 14:53:02 by emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	if (a->top && a->top->next)
	{
		a->top = a->top->next;
		a->bottom = a->bottom->next;
	}
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	if (b->top && b->top->next)
	{
		b->top = b->top->next;
		b->bottom = b->bottom->next;
	}
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	if (a->top && a->top->next)
	{
		a->top = a->top->next;
		a->bottom = a->bottom->next;
	}
	if (b->top && b->top->next)
	{
		b->top = b->top->next;
		b->bottom = b->bottom->next;
	}
	write(1, "rr\n", 3);
}

void	rra(t_stack *a)
{
	if (a->top && a->top->next)
	{
		a->top = a->top->prev;
		a->bottom = a->bottom->prev;
	}
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	if (b->top && b->top->next)
	{
		b->top = b->top->prev;
		b->bottom = b->bottom->prev;
	}
	write(1, "rrb\n", 4);
}
