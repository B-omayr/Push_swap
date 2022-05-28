/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_ps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:31:25 by iomayr            #+#    #+#             */
/*   Updated: 2022/04/14 18:29:13 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	avoiid_leaks(t_stack *stack)
{
	free(stack->stack_a);
	free(stack->stack_b);
	free(stack->lis);
	free(stack->sub);
	free(stack->arr);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	mouve_3_elements(t_stack *s)
{
	if (s->stack_a[0] > s->stack_a[1] && s->stack_a[1] < s->stack_a[2]
		&& s->stack_a[0] > s->stack_a[2])
	{
		sa(s);
		rra(s);
		sa(s);
	}
	if (s->stack_a[0] > s->stack_a[1] && s->stack_a[1] < s->stack_a[2])
		sa(s);
	else if (s->stack_a[0] > s->stack_a[2] && s->stack_a[1] < s->stack_a[2])
		ra(s);
	else if (s->stack_a[0] < s->stack_a[1] && s->stack_a[0] > s->stack_a[2])
		rra(s);
	else if (s->stack_a[0] < s->stack_a[2] && s->stack_a[2] < s->stack_a[1])
	{
		sa(s);
		ra(s);
	}
	else if (s->stack_a[0] > s->stack_a[1] && s->stack_a[1] > s->stack_a[2])
	{
		sa(s);
		rra(s);
	}
}
