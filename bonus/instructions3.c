/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:12:05 by iomayr            #+#    #+#             */
/*   Updated: 2022/04/14 17:25:06 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_bonus.h"

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
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
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

char	*ft_strjoiiin(char *s1, char *s2)
{
	char	*output;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2);
	output = (char *)malloc(sizeof(char) * len + 2);
	if (!output)
		return (0);
	while (s1[j])
		output[i++] = s1[j++];
	if (ft_strcmp(s1, "") != 0)
		output[i++] = 32;
	j = 0;
	while (s2[j])
		output[i++] = s2[j++];
	output[i] = 0;
	return (output);
}
