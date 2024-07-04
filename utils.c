/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:47:33 by emamati           #+#    #+#             */
/*   Updated: 2024/07/04 14:58:24 by emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

int	min(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

void	init_stack(t_stack *t_stack)
{
	t_stack->top = NULL;
	t_stack->bottom = NULL;
}

int	isempty(t_stack *t_stack)
{
	return (t_stack->top == NULL);
}

void	push(t_stack *stack, int data)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	newnode->data = data;
	newnode->next = stack->top;
	if (stack->bottom == NULL)
		stack->bottom = newnode;
	if (stack->top != NULL)
		stack->top->prev = newnode;
	stack->top = newnode;
	stack->top->prev = stack->bottom;
	stack->bottom->next = stack->top;
}
