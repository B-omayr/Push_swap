/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utiles_ps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:34:10 by iomayr            #+#    #+#             */
/*   Updated: 2022/04/13 15:15:29 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_in_a(t_stack *stack)
{
	int	i;
	int	max;

	i = -1;
	max = -2147483648;
	while (++i < stack->top_a)
	{
		if (stack->stack_a[i] > max)
		{
			stack->imax = i;
			max = stack->stack_a[i];
		}
	}
	return (max);
}

int	find_min_in_ai(t_stack *stack, t_find *find)
{
	int	i;
	int	min;

	i = -1;
	min = 2147483647;
	while (++i < stack->top_a)
	{
		if (stack->stack_a[i] < min)
		{
			find->jmin = i;
			min = stack->stack_a[i];
		}
	}
	return (min);
}

int	find_min_in_a(t_stack *stack)
{
	int	i;
	int	min;

	i = -1;
	min = 2147483647;
	while (++i < stack->top_a)
	{
		if (stack->stack_a[i] < min)
		{
			stack->jmin = i;
			min = stack->stack_a[i];
		}
	}
	return (min);
}

int	check_sort(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->top_a - 1)
	{
		if (stack->stack_a[i] < stack->stack_a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

void	final_sort(t_stack *stack)
{
	int	min_a;
	int	i;
	int	mid;

	i = -1;
	mid = (stack->top_a - 1) / 2;
	min_a = find_min_in_a(stack);
	while (stack->stack_a[0] != min_a)
	{
		if (stack->jmin > mid)
			rra(stack);
		else if (stack->jmin <= mid)
			ra(stack);
	}
}
