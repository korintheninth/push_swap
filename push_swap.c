/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:44:22 by emamati           #+#    #+#             */
/*   Updated: 2024/07/04 18:45:12 by emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	apply(t_stack *a, t_stack *b)
{
	t_node	*temp;

	temp = a->top;
	while (temp->moves != min_move(a))
		temp = temp->next;
	if (temp->moves == max(temp->aind, temp->bind))
		case_1(temp, a, b);
	else if (temp->moves == max(stacksize(a) - temp->aind, stacksize(b)
			- temp->bind))
		case_2(temp, a, b);
	else if (temp->moves == temp->bind + stacksize(a) - temp->aind)
		case_3(temp, a, b);
	else if (temp->moves == stacksize(b) - temp->bind + temp->aind)
		case_4(temp, a, b);
	pb(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	if (a && b)
	{
		init_stack(a);
		init_stack(b);
	}
	else
		return (-1);
	if (!parser(argc, argv, a))
	{
		free_stacks(a, b);
		return (-1);
	}
	if (stacksize(a) > 2)
		solve(a, b);
	if (stacksize(a) == 2 && a->top->data > a->bottom->data)
		sa(a);
	free_stacks(a, b);
}
