/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utiles3_ps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:41:27 by iomayr            #+#    #+#             */
/*   Updated: 2022/04/13 15:47:32 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_stack(t_stack *stack, int k)
{
	int	i;
	int	mid;
	int	pos;

	i = -1;
	mid = (stack->top_a - 1) / 2;
	while (++i < stack->top_a)
	{
		if (stack->stack_b[k] > stack->stack_a[i]
			&& stack->stack_b[k] < stack->stack_a[i + 1])
		{
			if (i > mid)
			{	
				pos = stack->top_a - i;
				return (pos);
			}
			else if (i <= mid)
			{
				pos = i + 2;
				return (pos);
			}
		}
	}
	return (0);
}

int	best_mouve_b(t_stack *stack, int k)
{
	int	i;
	int	ra;
	int	rra;
	int	mid;

	i = 0;
	mid = (stack->top_b - 1) / 2;
	if (k <= mid)
	{
		ra = k;
		return (ra);
	}
	else if (k > mid)
	{
		rra = stack->top_b - k;
		return (rra);
	}
	return (0);
}

void	mouve_in_b(t_stack *stack, int pos)
{
	int	i;
	int	j;
	int	h;
	int	mid;

	i = -1;
	j = -1;
	mid = (stack->top_b - 1) / 2;
	if (pos <= mid)
	{
		while (++i < pos)
			rb(stack);
	}
	else if (pos > mid)
	{
		h = stack->top_b - pos;
		while (++j < h)
			rrb(stack);
	}
}

int	check_top_bottomi(t_stack *stack, int k)
{
	if (stack->stack_b[k] > stack->stack_a[stack->top_a - 1]
		&& stack->stack_b[k] < stack->stack_a[0])
		return (1);
	if (stack->stack_b[k] < stack->stack_a[stack->top_a - 1]
		&& stack->stack_b[k] > stack->stack_a[0])
		return (2);
	return (0);
}

int	check_top_bottom(t_stack *stack)
{
	if (stack->stack_b[0] > stack->stack_a[stack->top_a - 1]
		&& stack->stack_b[0] < stack->stack_a[0])
	{
		pa(stack);
		return (1);
	}
	if (stack->stack_b[0] < stack->stack_a[stack->top_a - 1]
		&& stack->stack_b[0] > stack->stack_a[0])
	{
		rra(stack);
		pa(stack);
		return (1);
	}
	return (0);
}
