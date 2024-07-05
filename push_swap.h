/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:53:55 by emamati           #+#    #+#             */
/*   Updated: 2024/07/04 18:42:05 by emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# define INT32_MAX 2147483647
# define INT32_MIN -2147483648

typedef struct node
{
	int			data;
	int			moves;
	int			aind;
	int			bind;
	struct node	*next;
	struct node	*prev;
}				t_node;

typedef struct t_stack
{
	t_node		*top;
	t_node		*bottom;
}				t_stack;

int				max(int a, int b);
int				min(int a, int b);
void			init_stack(t_stack *stack);
int				isempty(t_stack *stack);
void			push(t_stack *stack, int data);
int				pop(t_stack *stack);
void			sa(t_stack *a);
void			sb(t_stack *b);
void			ss(t_stack *a, t_stack *b);
void			pa(t_stack *a, t_stack *b);
void			pb(t_stack *a, t_stack *b);
void			ra(t_stack *a);
void			rb(t_stack *b);
void			rr(t_stack *a, t_stack *b);
void			rra(t_stack *a);
void			rrb(t_stack *b);
void			rrr(t_stack *a, t_stack *b);
int				stacksize(t_stack *stack);
void			rota(t_stack *a, int b);
void			solve_for3(t_stack *a);
void			push_back(t_stack *a, t_stack *b);
void			set_movec(t_stack *stack_a, t_stack *stack_b);
int				min_move(t_stack *a);
void			solve(t_stack *a, t_stack *b);
void			moves(t_stack *a, t_stack *b, t_node *node);
void			case_1(t_node *temp, t_stack *a, t_stack *b);
void			case_2(t_node *temp, t_stack *a, t_stack *b);
void			case_3(t_node *temp, t_stack *a, t_stack *b);
void			case_4(t_node *temp, t_stack *a, t_stack *b);
void			free_stacks(t_stack *a, t_stack *b);
void			apply(t_stack *a, t_stack *b);
void			freeargs(char **args);
int				parser(int argc, char **argv, t_stack *a);

#endif
