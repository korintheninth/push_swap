/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:47:41 by emamati           #+#    #+#             */
/*   Updated: 2024/07/04 18:44:22 by emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	new_atoi(const char *str)
{
	int				i;
	int				mult;
	long long int	nb;

	mult = 1;
	nb = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	nb *= mult;
	return (nb);
}

int	check_max_min_int(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	if (new_atoi(arg) != 0 && arg[0] == 0)
		return (0);
	if (arg[1] == '0' && arg[0] == '-')
		return (0);
	if (new_atoi(arg) > INT32_MAX)
		return (0);
	if (new_atoi(arg) < INT32_MIN)
		return (0);
	return (1);
}

int	check_err(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		if (!check_max_min_int(argv[i]))
			return (0);
		j = 0;
		while (j < i)
		{
			if (argv[j] == argv[i])
				return (0);
				j++;
		}
		i++;
	}
	return (1);
}

void	fillstack(t_stack *a, char **args)
{
	int	i;

	i = 0;
	while (args[i++])
		push(a, ft_atoi(args[i]));
}

int	parser(int	argc, char **argv, t_stack *a)
{
	char	**args;
	int		i;

	if (argc == 1)
		return(0);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv;
	if (!check_err(args))
	{
		write(1, "Error", 5);
		if (args != argv)
			freeargs(args);
		return(0);
	}
	fillstack(a, args);
	if (args != argv)
		freeargs(args);
	return (1);
}
