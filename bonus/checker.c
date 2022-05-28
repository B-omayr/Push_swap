/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:02:19 by iomayr            #+#    #+#             */
/*   Updated: 2022/04/14 18:51:17 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_bonus.h"
#include <stdio.h>

void	ft_check_two(char *str, t_stack *stack)
{
	if (ft_strcmp(str, "pb") == 0)
		pb(stack);
	else if (ft_strcmp(str, "rr") == 0)
		rr(stack);
	else if (ft_strcmp(str, "rra") == 0)
		rra(stack);
	else if (ft_strcmp(str, "rrb") == 0)
		rrb(stack);
	else if (ft_strcmp(str, "rrr") == 0)
		rrr(stack);
	else
	{
		write(1, "Error\n", 6);
		free(str);
		exit(1);
	}
}

void	ft_check(char *str, t_stack *stack)
{
	if (ft_strcmp(str, "ra") == 0)
		ra(stack);
	else if (ft_strcmp(str, "rb") == 0)
		rb(stack);
	else if (ft_strcmp(str, "ss") == 0)
		ss(stack);
	else if (ft_strcmp(str, "sa") == 0)
		sa(stack);
	else if (ft_strcmp(str, "sb") == 0)
		sb(stack);
	else if (ft_strcmp(str, "pa") == 0)
		pa(stack);
	else
		ft_check_two(str, stack);
}

int	read_from_stdin(t_stack *stack)
{
	char	*input;
	char	c;

	input = NULL;
	while (read(0, &c, 1))
	{
		if (c == '\n')
		{
			ft_check(input, stack);
			free(input);
			input = ft_strdup("");
		}
		else
			input = ft_strjoiin(input, c);
	}
	free(input);
	return (0);
}

void	avoid_leaks(t_stack *stack)
{
	free(stack->stack_a);
}

int	main(int ac, char **av)
{
	t_stack	stack;

	if (ac == 1)
		exit (EXIT_FAILURE);
	check_elements(ac, av, &stack);
	read_from_stdin(&stack);
	if (check_sort(&stack) == 1)
		write(1, "OK\n", 3);
	if (check_sort(&stack) == 0)
		write(1, "KO\n", 3);
	avoid_leaks(&stack);
}
