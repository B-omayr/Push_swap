/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:09:19 by iomayr            #+#    #+#             */
/*   Updated: 2022/04/14 11:25:42 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(int count_line, int acc, t_stack *stack, int value)
{
	stack->max = 0;
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
