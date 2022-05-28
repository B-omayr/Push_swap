/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utiles2_ps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:39:14 by iomayr            #+#    #+#             */
/*   Updated: 2022/04/14 15:31:54 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mouve_to_sb(t_stack *s)
{
	int	mid;
	int	j;
	int	h;

	j = -1;
	mid = (s->top_a - 1) / 2;
	if (s->jmin <= mid)
	{
		while (++j < s->jmin)
			ra(s);
		pb(s);
	}
	else if (s->jmin > mid)
	{
		j = -1;
		h = s->top_a - s->jmin;
		while (++j < h)
			rra(s);
		pb(s);
	}
}

void	mouve_4_elements(t_stack *s)
{
	find_min_in_a(s);
	mouve_to_sb(s);
	mouve_3_elements(s);
	pa(s);
}

void	mouve_5_elements(t_stack *s)
{
	find_min_in_a(s);
	mouve_to_sb(s);
	find_min_in_a(s);
	mouve_to_sb(s);
	mouve_3_elements(s);
	pa(s);
	pa(s);
}

int	find_lenght(int count, t_stack *stack)
{
	int	i;
	int	j;
	int	x;
	int	*lis;
	int	stock;

	lis = malloc(sizeof(int) * count);
	if (!lis)
		exit (1);
	stock = 0;
	i = 0;
	x = -1;
	while (++x < count)
		lis[x] = 1;
	while (++i < stack->top_a)
	{
		j = -1;
		while (++j < i)
			if (stack->stack_a[i] > stack->stack_a[j] && lis[j] + 1 >= lis[i])
				lis[i] = lis[j] + 1;
		if (lis[i] > stock)
			stock = lis[i];
	}
	free(lis);
	return (stock);
}

void	get_arr_sub(int count, t_stack *stack)
{
	int	len;
	int	i;
	int	j;

	i = -1;
	len = find_lenght(count, stack);
	stack->arr = malloc(sizeof(int) * len);
	if (!stack->arr)
	{
		free(stack->arr);
		exit (1);
	}
	j = len;
	while (++i < len)
	{
		j--;
		stack->arr[i] = stack->stack_a[stack->sub[j]];
	}
}
