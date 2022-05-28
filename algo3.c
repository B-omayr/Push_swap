/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:12:54 by iomayr            #+#    #+#             */
/*   Updated: 2022/04/14 11:27:01 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_min(t_stack *stack)
{
	int	j;
	int	mid;
	int	min_a;

	j = -1;
	mid = (stack->top_a - 1) / 2;
	min_a = find_min_in_a(stack);
	if (stack->stack_b[0] < min_a)
	{
		if (stack->jmin <= mid)
		{
			while (++j < stack->jmin)
				ra(stack);
			pa(stack);
			return (1);
		}
		if (stack->jmin > mid)
		{
			while (++j < (stack->top_a - stack->jmin))
				rra(stack);
			pa(stack);
			return (1);
		}
	}
	return (0);
}

int	check_max(t_stack *stack)
{
	int	j;
	int	mid;
	int	max_a;

	j = -1;
	mid = (stack->top_a - 1) / 2;
	max_a = find_max_in_a(stack);
	if (stack->stack_b[0] > max_a)
	{
		if (stack->imax <= mid)
		{
			while (++j <= stack->imax)
				ra(stack);
			pa(stack);
			return (1);
		}
		else if (stack->imax > mid)
		{
			while (++j < ((stack->top_a - 1) - stack->imax))
				rra(stack);
			pa(stack);
			return (1);
		}
	}
	return (0);
}

int	get_position_in_a(t_stack *stack)
{
	int	i;

	i = -1;
	if (check_max(stack))
		return (1);
	if (check_min(stack))
		return (1);
	while (++i < stack->top_a)
	{
		if (stack->stack_b[0] > stack->stack_a[i]
			&& stack->stack_b[0] < stack->stack_a[i + 1])
		{
			stack->pos = i;
			return (0);
		}
	}
	if (check_top_bottom(stack))
		return (1);
	return (0);
}

void	move_stack_a(t_stack *stack)
{
	int	j;
	int	x;
	int	mid;

	j = -1;
	mid = (stack->top_a - 1) / 2;
	if (stack->pos <= mid)
	{
		while (++j <= stack->pos)
			ra(stack);
		pa(stack);
		return ;
	}
	else if (stack->pos > mid)
	{
		x = (stack->top_a - 1) - stack->pos;
		while (++j < x)
			rra(stack);
		pa(stack);
		return ;
	}
}

void	mouve_to_a(t_stack *stack)
{
	if (!get_position_in_a(stack))
		move_stack_a(stack);
}
