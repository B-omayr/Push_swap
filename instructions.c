/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:39:12 by iomayr            #+#    #+#             */
/*   Updated: 2022/04/14 16:03:19 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	int	swap;

	if (stack->top_a >= 2)
	{
		swap = stack->stack_a[0];
		stack->stack_a[0] = stack->stack_a[1];
		stack->stack_a[1] = swap;
	}
	write(1, "sa\n", 3);
}

void	reverse_b(t_stack *stack)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	if (stack->top_b > 0)
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
		while (++i < stack->top_a)
			stack->stack_a[i] = stack->stack_a[i + 1];
	}
	write(1, "pb\n", 3);
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
	write(1, "pa\n", 3);
}
