/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:50:26 by emamati           #+#    #+#             */
/*   Updated: 2024/07/04 18:37:57 by emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_nodes(t_stack *stack)
{
	t_node	*curr;
	t_node	*temp;
	
	if (stack->bottom && stack->bottom->next)
		stack->bottom->next = NULL;
	if (stack->top)
	{
		curr = stack->top;
		while (curr->next)
		{
			temp = curr;
			curr = curr->next;
			free(temp);
		}
	}
}

void	free_stacks(t_stack *a, t_stack *b)
{
	if (a)
	{
		free_nodes(a);
		free(a);
	}
	if (b)
	{
		free_nodes(b);
		free(b);
	}
}

void	freeargs(char **args)
{
	int	i;
	
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}