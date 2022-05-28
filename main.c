/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:24:03 by iomayr            #+#    #+#             */
/*   Updated: 2022/04/14 18:29:05 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	mouve_2_elements(t_stack *stack)
{
	if (stack->stack_a[0] > stack->stack_a[1])
		sa(stack);
	else if (stack->stack_a[1] > stack->stack_a[0])
		return (0);
	return (0);
}

int	check_min_argc(t_stack *stack)
{
	if (stack->count_line == 2)
		mouve_2_elements(stack);
	if (stack->count_line == 3)
		mouve_3_elements(stack);
	if (stack->count_line == 4)
		mouve_4_elements(stack);
	if (stack->count_line == 5)
		mouve_5_elements(stack);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	stack;
	t_find	find;

	if (ac == 1)
		return (0);
	check_elements(ac, av, &stack);
	if (check_sort(&stack) == 1)
		exit (0);
	check_min_argc(&stack);
	if (stack.count_line >= 6)
	{
		find_lis(&stack);
		while (stack.top_b)
			get_best_mouve(&stack, &find);
		final_sort(&stack);
		free(stack.curr);
	}
	avoiid_leaks(&stack);
}
