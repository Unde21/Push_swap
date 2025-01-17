/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:12:32 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/17 02:56:12 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push (t_stack **stack_a, t_stack **stack_b, char c)
{
	t_stack	*first_elem_a;
	t_stack	*first_elem_b;
	t_stack	*new;

	new = NULL;
	first_elem_a = *stack_a;
	first_elem_b = *stack_b;
	(void)c; // a retirer
	if (c == 'a')
	{
		new = new_stack(first_elem_b->value);
		if (!new)
			return ;
		stack_add_front(stack_a, new);
		if (stack_size(*stack_b) > 1)
			*stack_b = first_elem_b->next;
		else
			*stack_b = NULL;
		// ft_printf("p%c\n", c);
		free(first_elem_b);
	}
	else if (c == 'b' && first_elem_a->empty != true)
	{
		new = new_stack(first_elem_a->value);
		if (!new)
			return ;
		stack_add_front(stack_b, new);
		if (stack_size(*stack_a) > 1)
			*stack_a = first_elem_a->next;
		else
			*stack_b = NULL;
		// ft_printf("p%c\n", c);
		free(first_elem_a);
	}
}
