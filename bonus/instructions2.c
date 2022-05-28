/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:10:29 by iomayr            #+#    #+#             */
/*   Updated: 2022/04/14 13:23:23 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_bonus.h"

void	reverse_b(t_stack *stack)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	stack->stack_b[stack->top_b] = stack->stack_b[stack->top_b - 1];
	while (stack->top_b > i)
	{
		stack->stack_b[stack->top_b - i] = stack->stack_b[stack->top_b - j];
		i++;
		j++;
	}
}

void	pb(t_stack *stack)
{
	int	i;

	i = -1;
	if (stack->top_a > 0)
	{
		reverse_b(stack);
		stack->stack_b[0] = stack->stack_a[0];
		stack->top_b++;
		stack->top_a--;
		while (++i <= stack->top_a)
			stack->stack_a[i] = stack->stack_a[i + 1];
	}
}

void	reverse_a(t_stack *stack)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	stack->stack_a[stack->top_a] = stack->stack_a[stack->top_a - 1];
	while (stack->top_a > i)
	{
		stack->stack_a[stack->top_a - i] = stack->stack_a[stack->top_a - j];
		i++;
		j++;
	}
}

void	pa(t_stack *stack)
{
	int	i;

	i = -1;
	if (stack->top_b > 0)
	{
		reverse_a(stack);
		stack->stack_a[0] = stack->stack_b[0];
		stack->top_a++;
		stack->top_b--;
		while (++i < stack->top_b)
			stack->stack_b[i] = stack->stack_b[i + 1];
	}
}

void	ra(t_stack *stack)
{
	int	i;
	int	j;
	int	swap;

	i = 1;
	j = 0;
	swap = stack->stack_a[0];
	while (i < stack->top_a)
	{
		stack->stack_a[j] = stack->stack_a[i];
		i++;
		j++;
	}
	stack->stack_a[stack->top_a - 1] = swap;
}
