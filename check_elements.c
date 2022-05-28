/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:23:38 by iomayr            #+#    #+#             */
/*   Updated: 2022/04/14 18:34:16 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_negative(t_stack *stack, int i)
{
	int	j;
	int	x;

	j = 0;
	x = 0;
	if (stack->pars[i][0] == 45 && stack->pars[i][1] == '\0')
	{
		write(1, "Error\n", 6);
		exit (0);
	}
	else if (stack->pars[i][0] == 45 || stack->pars[i][0] == 43)
	{
		while (++x < ft_strlen(stack->pars[i]))
		{
			if (stack->pars[i][x] < 48 || stack->pars[i][x] > 57)
			{
				write(1, "Error\n", 6);
				exit (0);
			}
		}
	}
}

void	check_integer(t_stack *stack)
{
	int	i;
	int	j;
	int	x;

	x = 0;
	i = -1;
	while (++i < stack->count_line)
	{
		check_negative(stack, i);
		j = -1;
		while (++j < ft_strlen(stack->pars[i]))
		{
			if ((stack->pars[i][j] < 48 && stack->pars[i][0] != 45)
				|| (stack->pars[i][j] > 57 && stack->pars[i][0] != 45))
			{
				if (stack->pars[i][0] != 43)
				{
					write(1, "Error\n", 6);
					exit(0);
				}
			}	
		}
	}
}

void	check_duplicate(t_stack *stack)
{
	int	i;
	int	j;

	i = -1;
	while (++i < stack->count_line - 1)
	{
		if (ft_strcmp(stack->pars[i], "") == 0)
		{
			write (1, "Error\n", 6);
			exit (0);
		}
		j = i + 1;
		while (j < stack->count_line)
		{
			if (ft_atoi(stack->pars[i]) == ft_atoi(stack->pars[j]))
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			j++;
		}
	}
}

int	ft_check(t_stack *stack)
{
	int	i;

	i = -1;
	if (stack->count_line >= 1)
	{
		while (++i < stack->count_line)
		{
			if ((ft_atoi(stack->pars[i]) > 2147483647)
				|| (ft_atoi(stack->pars[i]) < -2147483648))
			{
				write(1, "Error\n", 6);
				exit(0);
			}
		}
		check_duplicate(stack);
		check_integer(stack);
	}
	return (0);
}

void	check_elements(int ac, char **av, t_stack *stack)
{
	int		i;
	char	*tmp;

	i = 0;
	stack->save = NULL;
	while (++i < ac)
	{
		if (ft_strlen(av[i]) == 0)
		{
			write (1, "Error\n", 6);
			exit (0);
		}
		tmp = stack->save;
		stack->save = ft_strjoin(stack->save, av[i]);
		free(tmp);
	}
	stack->pars = ft_split(stack->save, ' ');
	free(stack->save);
	i = 0;
	while (stack->pars[i])
		i++;
	stack->count_line = i;
	ft_check(stack);
	init(stack);
	avoid_pars(stack);
}
