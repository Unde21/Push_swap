/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 01:21:23 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/17 02:55:27 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap (t_stack **stack, char c)
{
	t_stack	*first_elem;
	t_stack	*second_elem;
	int	swap;

	(void)c; // a retirer
	first_elem = *stack;
	second_elem = NULL;
	if (stack_size(*stack) <= 1)
		return ;
	second_elem = first_elem->next;
	swap = first_elem->value;
	first_elem->value = second_elem->value;
	second_elem->value = swap;
	// ft_printf("s%c\n", c);
}

void	swap_ab (t_stack **stack_a, t_stack **stack_b)  // a revoir pour l affichage ss si une des 2 conditions n est pas rempli
{
	t_stack	*first_elem;
	t_stack	*second_elem;
	int	swap;

	first_elem = *stack_a;
	second_elem = NULL;
	if (stack_size(*stack_a) > 1)
	{
		second_elem = first_elem->next;	
		swap = first_elem->value;
		first_elem->value = second_elem->value;
		second_elem->value = swap;
	}
	first_elem = *stack_b;
	if (stack_size(*stack_b) > 1)
	{
		second_elem = first_elem->next;	
		swap = first_elem->value;
		first_elem->value = second_elem->value;
		second_elem->value = swap;
	}
	// ft_printf("ss\n");
}
