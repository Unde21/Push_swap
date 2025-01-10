/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:13:00 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/10 20:25:09 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate (t_list **stack, char c)
{
	t_list	*first_elem;
	
	first_elem = *stack;
	if (ft_lstsize(*stack) > 1 && first_elem->content != NULL)
	{	
		*stack = first_elem->next;
		ft_lstadd_back(stack, first_elem);
		first_elem->next = NULL;
		ft_printf("r%c\n", c);
	}
}

void	rotate_ab (t_list **stack_a, t_list **stack_b)   // a revoir pour l affichage rr si une des 2 conditions n est pas rempli
{
	t_list	*first_elem;
	
	first_elem = *stack_a;
	if (ft_lstsize(*stack_a) > 1 && first_elem->content != NULL)
	{	
		*stack_a = first_elem->next;
		ft_lstadd_back(stack_a, first_elem);
		first_elem->next = NULL;
	}
	first_elem = *stack_b;
	if (ft_lstsize(*stack_b) > 1 && first_elem->content != NULL)
	{	
		*stack_b = first_elem->next;
		ft_lstadd_back(stack_b, first_elem);
		first_elem->next = NULL;
	}
	ft_printf("rr\n");
}
