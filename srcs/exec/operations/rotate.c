/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:13:00 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/20 04:29:33 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack, char c)
{
	t_stack	*first_elem;

	first_elem = *stack;
	if (stack_size(*stack) > 1)
	{
		*stack = first_elem->next;
		stack_add_back(stack, first_elem);
		first_elem->next = NULL;
		if (c != 'n')
			ft_printf("r%c\n", c);
	}
}

void	rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_elem;

	first_elem = *stack_a;
	if (stack_size(*stack_a) > 1 && first_elem->empty != true)
	{
		*stack_a = first_elem->next;
		stack_add_back(stack_a, first_elem);
		first_elem->next = NULL;
	}
	first_elem = *stack_b;
	if (stack_size(*stack_b) > 1 && first_elem->empty != true)
	{
		*stack_b = first_elem->next;
		stack_add_back(stack_b, first_elem);
		first_elem->next = NULL;
	}
}

void	b_rotate(t_stack **stack_b, int *pos, int *top_index)
{
	rotate(stack_b, 'b');
	*top_index = (*stack_b)->sort_index;
	--(*pos);
}
