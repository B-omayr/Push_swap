/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:18:46 by iomayr            #+#    #+#             */
/*   Updated: 2022/04/14 20:01:57 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_bonus.h"

void	ft_push(int count_line, int acc, t_stack *stack, int value)
{
	if (++stack->top_a <= count_line)
		stack->stack_a[acc] = value;
}

void	init(t_stack *stack)
{
	int	i;
	int	acc;

	i = -1;
	acc = stack->count_line;
	stack->top_a = 0;
	stack->top_b = 0;
	stack->ptr = malloc(sizeof(int) * acc);
	if (!stack->ptr)
		exit (1);
	while (++i < stack->count_line)
		stack->ptr[i] = ft_atoi(stack->pars[i]);
	stack->stack_a = malloc(sizeof(int) * stack->count_line);
	if (!stack->stack_a)
		exit (1);
	stack->stack_b = malloc(sizeof(int) * stack->count_line);
	if (!stack->stack_b)
		exit (1);
	while (--acc >= 0)
		ft_push(stack->count_line, acc, stack, stack->ptr[acc]);
	free(stack->ptr);
}

void	avoid_pars(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->pars[i])
	{
		free(stack->pars[i]);
		i++;
	}
	free(stack->pars);
}
