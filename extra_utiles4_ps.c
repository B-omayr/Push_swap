/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utiles4_ps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:37:38 by iomayr            #+#    #+#             */
/*   Updated: 2022/04/14 18:34:27 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
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

char	*ft_strdup(char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!ptr)
		return (0);
	while (str[i])
	{
		ptr[i] = (char)str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	avoid_pars(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->pars[i])
	{
		free(stack->pars[i]);
		i++;
	}
	free(stack->pars);
}
