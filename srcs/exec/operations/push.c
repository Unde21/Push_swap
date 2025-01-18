/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:12:32 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/18 06:55:28 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



// void	push (t_stack **stack_a, t_stack **stack_b, char c)
// {
// 	t_stack	*first_elem_a;
// 	t_stack	*first_elem_b;
// 	t_stack	*new;

// 	new = NULL;
// 	first_elem_a = *stack_a;
// 	first_elem_b = *stack_b;
// 	// (void)c; // a retirer
// 	if (c == 'a')
// 	{
// 		new = new_stack(first_elem_b->value, first_elem_b->sort_index);
// 		if (!new)
// 			return ;
// 		stack_add_front(stack_a, new);
// 		// if (stack_size(*stack_b) > 1)
// 			*stack_b = first_elem_b->next;
// 		// else
// 		// 	*stack_b = NULL;
// 		// ft_printf("p%c\n", c);
// 		free(first_elem_b);
// 	}
// 	else if (c == 'b')
// 	{
// 		new = new_stack(first_elem_a->value, first_elem_a->sort_index);
// 		if (!new)
// 			return ;
// 		stack_add_front(stack_b, new);
// 		// if (stack_size(*stack_a) > 1)
// 			*stack_a = first_elem_a->next;
// 		// else
// 		// 	*stack_b = NULL;
// 		// ft_printf("p%c\n", c);
// 		free(first_elem_a);
// 	}
// }

void 	push (t_stack **stack_a, t_stack **stack_b, char c)
{
	t_stack *tmp;

	if (c == 'b' && *stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = (*stack_b);
		//stack_add_front(stack_a, *stack_b);
		*stack_b = tmp;
	}
	else if (c == 'a' && *stack_b)
	{
		// print_lst(*stack_b, 'b', 0);
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = (*stack_a);
		//stack_add_front(stack_a, *stack_b);
		*stack_a = tmp;
		// print_lst(*stack_b, 'b', 0);
	}
}
