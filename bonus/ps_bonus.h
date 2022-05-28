/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:05:13 by iomayr            #+#    #+#             */
/*   Updated: 2022/04/14 20:02:13 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_BONUS_H
# define PS_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_stack{
	char	**pars;
	char	*save;
	int		count_line;
	int		*stack_a;
	int		*stack_b;
	int		*ptr;
	int		top_a;
	int		top_b;
}t_stack;

long long int	ft_atoi(const	char	*str);
char			*get_next_line(int fd);
char			*ft_strdup(char *str);
char			*ft_strjoiiin(char *s1, char *s2);
char			*ft_strjoiin(char *s1, char c);
char			**ft_split(char const *s, char c);
int				ft_strlen(char const *str);
int				ft_strcmp(char *s1, char *s2);
int				check_sort(t_stack *stack);
void			init(t_stack *stack);
void			avoid_pars(t_stack *stack);
void			check_elements(int ac, char **av, t_stack *stack);
void			rrb(t_stack *stack);
void			rra(t_stack *stack);
void			rb(t_stack *stack);
void			ss(t_stack *stack);
void			ra(t_stack *stack);
void			reverse_a(t_stack *stack);
void			reverse_b(t_stack *stack);
void			sb(t_stack *stack);
void			sa(t_stack *stack);
void			rrr(t_stack *stack);
void			pa(t_stack *stack);
void			pb(t_stack *stack);
void			rr(t_stack *stack);
void			rra(t_stack *stack);
void			rrb(t_stack *stack);

#endif