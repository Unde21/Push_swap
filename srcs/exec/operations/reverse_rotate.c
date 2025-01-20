/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:14:45 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/19 23:59:20 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last_elem;
	t_stack	*first_elem;

	first_elem = *stack;
	last_elem = *stack;
	if (stack_size(*stack) > 1)
	{
		while (last_elem->next->next != NULL)
			last_elem = last_elem->next;
		stack_add_front(stack, last_elem->next);
		last_elem->next = NULL;
	}
}

void	reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*last_elem;
	t_stack	*first_elem;

	first_elem = *stack_a;
	last_elem = *stack_a;
	if (stack_size(*stack_a) > 1)
	{
		while (last_elem->next->next != NULL)
			last_elem = last_elem->next;
		stack_add_front(stack_a, last_elem->next);
		last_elem->next = NULL;
	}
	first_elem = *stack_b;
	last_elem = *stack_b;
	if (stack_size(*stack_b) > 1)
	{
		while (last_elem->next->next != NULL)
			last_elem = last_elem->next;
		stack_add_front(stack_b, last_elem->next);
		last_elem->next = NULL;
	}
}

void	b_reverse_rotate(t_stack **stack_b, int *pos, int *top_index)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
	*top_index = (*stack_b)->sort_index;
	++(*pos);
}
