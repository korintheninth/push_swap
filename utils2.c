/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:48:57 by emamati           #+#    #+#             */
/*   Updated: 2024/07/04 16:03:52 by emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pop(t_stack *stack)
{
	t_node	*temp;
	int		poppeddata;

	temp = stack->top;
	poppeddata = temp->data;
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
	return (poppeddata);
}

int	stacksize(t_stack *stack)
{
	t_node	*curr;
	int		size;

	if (stack->top == NULL)
		return (0);
	curr = stack->top->next;
	size = 1;
	while (curr != stack->top)
	{
		curr = curr->next;
		size++;
	}
	return (size);
}

void	rrr(t_stack *a, t_stack *b)
{
	if (a->top && a->top->next)
	{
		a->top = a->top->prev;
		a->bottom = a->bottom->prev;
	}
	if (b->top && b->top->next)
	{
		b->top = b->top->prev;
		b->bottom = b->bottom->prev;
	}
	write(1, "rrr\n", 4);
}
