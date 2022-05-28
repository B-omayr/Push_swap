/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructiions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:38:48 by iomayr            #+#    #+#             */
/*   Updated: 2022/04/14 13:23:53 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_bonus.h"

void	sa(t_stack *stack)
{
	int	swap;

	if (stack->top_a >= 2)
	{
		swap = stack->stack_a[0];
		stack->stack_a[0] = stack->stack_a[1];
		stack->stack_a[1] = swap;
	}
}

void	sb(t_stack *stack)
{
	int	swap;

	if (stack->top_b >= 2)
	{
		swap = stack->stack_b[0];
		stack->stack_b[0] = stack->stack_b[1];
		stack->stack_b[1] = swap;
	}
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
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
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
}
