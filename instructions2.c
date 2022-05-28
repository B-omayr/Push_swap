/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:20:09 by iomayr            #+#    #+#             */
/*   Updated: 2022/04/13 15:36:16 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack *stack)
{
	int	swap;

	if (stack->top_b >= 2)
	{
		swap = stack->stack_b[0];
		stack->stack_b[0] = stack->stack_b[1];
		stack->stack_b[1] = swap;
	}
	write(1, "sb\n", 3);
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
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack)
{
	int	i;
	int	j;
	int	swap;

	i = 1;
	j = 0;
	swap = stack->stack_b[0];
	while (i < stack->top_b)
	{
		stack->stack_b[j] = stack->stack_b[i];
		i++;
		j++;
	}
	stack->stack_b[stack->top_b - 1] = swap;
	write(1, "rb\n", 3);
}

void	rra(t_stack *stack)
{
	int	swap;
	int	i;
	int	j;

	i = 1;
	j = 0;
	swap = stack->stack_a[stack->top_a - 1];
	while (i <= stack->top_a)
	{
		stack->stack_a[stack->top_a - j] = stack->stack_a[stack->top_a - i];
		i++;
		j++;
	}
	stack->stack_a[0] = swap;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
{
	int	swap;
	int	i;
	int	j;

	i = 2;
	j = 1;
	swap = stack->stack_b[stack->top_b - 1];
	while (i <= stack->top_b)
	{
		stack->stack_b[stack->top_b - j] = stack->stack_b[stack->top_b - i];
		i++;
		j++;
	}
	stack->stack_b[0] = swap;
	write(1, "rrb\n", 4);
}
