/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:32:53 by iomayr            #+#    #+#             */
/*   Updated: 2022/04/14 15:37:35 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_sub_in_stack_a(int count, t_stack *stack)
{
	int	i;
	int	len;
	int	j;

	len = find_lenght(count, stack);
	j = stack->top_a ;
	while (--j >= 0)
	{
		i = -1;
		while (++i < len)
		{
			if (stack->stack_a[0] == stack->arr[i])
			{
				ra(stack);
				break ;
			}
			else if (i == len - 1 && stack->stack_a[0] != stack->arr[i])
			{
				pb(stack);
				break ;
			}
		}
	}
}

void	find_subsquence(int count, t_stack *stack, int *curr)
{
	int	i;
	int	len;
	int	j;

	len = find_lenght(count, stack);
	stack->sub = malloc(sizeof(int) * len);
	if (!stack->sub)
	{
		free(stack->sub);
		exit (1);
	}
	i = 0;
	j = 0;
	stack->sub[0] = curr[0];
	while (++i < len)
	{
		j = curr[j];
		stack->sub[i] = curr[j];
	}
	get_arr_sub(count, stack);
	get_sub_in_stack_a(count, stack);
}

void	get_lis(t_stack *stack, int i)
{
	int	j;

	j = -1;
	while (++j < i)
	{
		if (stack->stack_a[i] > stack->stack_a[j]
			&& stack->lis[j] + 1 >= stack->lis[i])
		{
			stack->lis[i] = stack->lis[j] + 1;
			stack->curr[i] = j;
			if (stack->lis[i] > stack->lis[stack->max])
			{
				stack->curr[0] = i;
				stack->max = i;
			}
		}
	}
}

void	find_lis(t_stack *stack)
{
	int	i;

	stack->curr = malloc(sizeof(int) * stack->count_line);
	if (!stack->curr)
	{
		free(stack->curr);
		exit (1);
	}
	stack->lis = malloc(sizeof(int) * stack->count_line);
	if (!stack->lis)
	{
		free(stack->lis);
		exit (1);
	}
	i = -1;
	while (++i < stack->count_line)
		stack->lis[i] = 1;
	i = 0;
	while (++i < stack->top_a)
		get_lis(stack, i);
	find_subsquence(stack->count_line, stack, stack->curr);
}
