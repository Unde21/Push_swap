/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:14:45 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/10 20:25:19 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **stack, char c)
{
	t_list	*last_elem;
	t_list	*first_elem;

	first_elem = *stack;
	last_elem = *stack;
	if (ft_lstsize(*stack) > 1)
	{
		while (last_elem->next->next != NULL)
			last_elem = last_elem->next;
		ft_lstadd_front(stack, last_elem->next);
		last_elem->next = NULL;
		ft_printf("rr%c\n", c);
	}
}

void	reverse_rotate_ab(t_list **stack_a, t_list **stack_b)  // a revoir pour l affichage rrr si une des 2 conditions n est pas rempli
{
	t_list	*last_elem;
	t_list	*first_elem;

	first_elem = *stack_a;
	last_elem = *stack_a;
	if (ft_lstsize(*stack_a) > 1)
	{
		while (last_elem->next->next != NULL)
			last_elem = last_elem->next;
		ft_lstadd_front(stack_a, last_elem->next);
		last_elem->next = NULL;
	}
	first_elem = *stack_b;
	last_elem = *stack_b;
	if (ft_lstsize(*stack_b) > 1)
	{
		while (last_elem->next->next != NULL)
			last_elem = last_elem->next;
		ft_lstadd_front(stack_b, last_elem->next);
		last_elem->next = NULL;
	}
	ft_printf("rrr\n");
}
