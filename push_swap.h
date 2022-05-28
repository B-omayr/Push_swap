/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:31:54 by iomayr            #+#    #+#             */
/*   Updated: 2022/04/14 18:34:43 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack{
	char	**pars;
	char	*save;
	int		count_line;
	int		*stack_a;
	int		*stack_b;
	int		top_a;
	int		top_b;
	int		*ptr;
	int		*curr;
	int		*lis;
	int		*sub;
	int		*arr;
	int		max;
	int		pos;
	int		imax;
	int		jmin;
}t_stack;

typedef struct s_sort{
	int	imax;
	int	jmin;
	int	pos;
}t_find;

long long int	ft_atoi(const char *str);
int				ft_strlen(char const *str);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(char *str);
char			**ft_split(char const *s, char c);
void			mouve_3_elements(t_stack *s);
void			mouve_4_elements(t_stack *s);
void			mouve_5_elements(t_stack *s);
void			mouve_in_b(t_stack *stack, int pos);
int				best_mouve_b(t_stack *stack, int k);
void			mouve_to_a(t_stack *stack);
int				best_mouve_a(t_stack *stack, t_find *find, int k);
int				get_best_mouve(t_stack *stack, t_find *find);
int				check_stack(t_stack *stack, int k);
void			check_elements(int ac, char **av, t_stack *stack);
int				check_top_bottom(t_stack *stack);
int				check_top_bottomi(t_stack *stack, int k);
int				check_sort(t_stack *stack);
void			final_sort(t_stack *stack);
void			init(t_stack *stack);
void			avoid_pars(t_stack *stack);
void			find_lis(t_stack *stack);
void			get_arr_sub(int count, t_stack *stack);
int				find_lenght(int count, t_stack *stack);
int				find_min_in_ai(t_stack *stack, t_find *find);
int				find_min_in_a(t_stack *stack);
int				find_max_in_a(t_stack *stack);
void			avoiid_leaks(t_stack *stack);
void			sb(t_stack *stack);
void			sa(t_stack *stack);
void			pa(t_stack *stack);
void			pb(t_stack *stack);
void			ra(t_stack *stack);
void			rb(t_stack *stack);
void			rra(t_stack *stack);
void			rrb(t_stack *stack);

#endif
