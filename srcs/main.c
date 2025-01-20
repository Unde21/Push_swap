/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 04:42:01 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/20 03:15:31 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*stack_c;

	stack_c = NULL;
	stack_b = NULL;
	stack_a = NULL;
	if (argc <= 2)
		return (0);
	if (parse_stack(argc, argv) == 0)
	{
		if (init_stack_a(argc, argv, &stack_a) != 0)
		{
			stack_clear(&stack_a);
			return (-1);
		}
		run(&stack_a, stack_b, stack_c);
		stack_clear(&stack_a);
	}
	return (0);
}

void	run(t_stack **stack_a, t_stack *stack_b, t_stack *stack_c)
{
	if (is_sort(*stack_a) == 0)
		return ;
	if (ft_lstcpy(stack_a, &stack_c) != 0)
		return ;
	init_index_stackcpy(stack_c, 0);
	first_sort(&stack_c, &stack_b);
	init_index_stackcpy(stack_c, 1);
	cpy_index_sort(*stack_a, stack_c);
	stack_clear(&stack_c);
	sandlass_algo(stack_a, stack_b);
}
