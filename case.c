/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:34:59 by emamati           #+#    #+#             */
/*   Updated: 2024/07/04 16:46:38 by emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_1(t_node *temp, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (i < min(temp->aind, temp->bind))
	{
		rr(a, b);
		i++;
	}
	if (temp->aind > temp->bind)
	{
		while (i < temp->moves)
		{
			ra(a);
			i++;
		}
	}
	else
	{
		while (i < temp->moves)
		{
			rb(b);
			i++;
		}
	}
}

void	case_2(t_node *temp, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (i < min(stacksize(a) - temp->aind, stacksize(b) - temp->bind))
	{
		rrr(a, b);
		i++;
	}
	if (stacksize(a) - temp->aind > stacksize(b) - temp->bind)
	{
		while (i < temp->moves)
		{
			rra(a);
			i++;
		}
	}
	else
	{
		while (i < temp->moves)
		{
			rrb(b);
			i++;
		}
	}
}

void	case_3(t_node *temp, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
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

void	case_4(t_node *temp, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
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
