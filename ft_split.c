/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 22:06:13 by iomayr            #+#    #+#             */
/*   Updated: 2022/04/14 13:54:36 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find(const char *s, char c)
{
	int	p;
	int	j;

	p = 1;
	j = 1;
	while (s && s[j] != '\0')
	{
		if (s[j] == c)
		{
			if (s[j + 1] == c)
				p -= 1;
			else if (s[j + 1] == '\0')
				p -= 1;
			p++;
		}
		j++;
	}
	return (p);
}

static char	*ft_print(const char *s, size_t start, size_t end)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc((end - start + 1) * (sizeof(char)));
	while (start < end)
	{
		ptr[i] = s[start];
		start++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		p;
	int		j;
	int		i;

	i = -1;
	j = 0;
	p = -1;
	if (!s)
		return (0);
	ptr = malloc(sizeof(char *) * (find(s, c) + 1));
	if (!ptr)
		return (0);
	while (++p <= ft_strlen(s))
	{
		if (s[p] != c && i < 0)
			i = p;
		else if ((s[p] == c || p == ft_strlen(s)) && i >= 0)
		{
			ptr[j++] = ft_print(s, i, p);
			i = -1;
		}
	}
	ptr[j] = 0;
	return (ptr);
}
