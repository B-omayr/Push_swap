/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:24:33 by iomayr            #+#    #+#             */
/*   Updated: 2022/04/13 14:32:46 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_mini(t_stack *stack, t_find *find, int k)
{
	int	pos;
	int	mid;
	int	min_a;

	mid = (stack->top_a - 1) / 2;
	min_a = find_min_in_ai(stack, find);
	if (stack->stack_b[k] < min_a)
	{
		if (find->jmin <= mid)
			return (find->jmin + 1);
		if (find->jmin > mid)
		{
			pos = stack->top_a - find->jmin + 1;
			return (pos);
		}
	}
	return (0);
}

int	find_max_in_ai(t_stack *stack, t_find *find)
{
	int	i;
	int	max;

	i = -1;
	max = -2147483648;
	while (++i < stack->top_a)
	{
		if (stack->stack_a[i] > max)
		{
			find->imax = i;
			max = stack->stack_a[i];
		}
	}
	return (max);
}

int	check_maxi(t_stack *stack, t_find *find, int k)
{
	int	pos;
	int	mid;
	int	max_a;

	mid = (stack->top_a - 1) / 2;
	max_a = find_max_in_ai(stack, find);
	if (stack->stack_b[k] > max_a)
	{
		if (find->imax <= mid)
		{
			pos = find->imax + 2;
			return (pos);
		}
		else if (find->imax > mid)
		{
			if (max_a == stack->stack_a[stack->top_a - 1])
				return (1);
			pos = stack->top_a - find->imax;
			return (pos);
		}
	}
	return (0);
}

int	best_mouve_a(t_stack *stack, t_find *find, int k)
{
	int	pos;

	if (check_maxi(stack, find, k))
	{
		pos = check_maxi(stack, find, k);
		return (pos);
	}
	if (check_mini(stack, find, k))
	{
		pos = check_mini(stack, find, k);
		return (pos);
	}
	if (check_stack(stack, k))
	{
		pos = check_stack(stack, k);
		return (pos);
	}
	if (check_top_bottomi(stack, k))
	{
		pos = check_top_bottomi(stack, k);
		return (pos);
	}
	return (0);
}

int	get_best_mouve(t_stack *stack, t_find *find)
{
	int	i;
	int	pos;
	int	curr;
	int	min;

	i = -1;
	curr = 1000;
	while (++i < stack->top_b)
	{
		min = best_mouve_b(stack, i) + best_mouve_a(stack, find, i);
		if (min < curr)
		{
			curr = min;
			pos = i;
		}
	}
	mouve_in_b(stack, pos);
	mouve_to_a(stack);
	return (0);
}
