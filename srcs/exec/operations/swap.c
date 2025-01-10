/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 01:21:23 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/10 20:12:58 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap (t_list **stack, char c)
{
	t_list	*first_elem;
	t_list	*second_elem;
	void	*swap;

	first_elem = *stack;
	second_elem = NULL;
	if (ft_lstsize(*stack) <= 1)
		return ;
	second_elem = first_elem->next;
	swap = first_elem->content;
	first_elem->content = second_elem->content;
	second_elem->content = swap;
	ft_printf("s%c\n", c);
}

void	swap_ab (t_list **stack_a, t_list **stack_b)  // a revoir pour l affichage ss si une des 2 conditions n est pas rempli
{
	t_list	*first_elem;
	t_list	*second_elem;
	void	*swap;

	first_elem = *stack_a;
	second_elem = NULL;
	if (ft_lstsize(*stack_a) > 1)
	{
		second_elem = first_elem->next;	
		swap = first_elem->content;
		first_elem->content = second_elem->content;
		second_elem->content = swap;
	}
	first_elem = *stack_b;
	if (ft_lstsize(*stack_b) > 1)
	{
		second_elem = first_elem->next;	
		swap = first_elem->content;
		first_elem->content = second_elem->content;
		second_elem->content = swap;
	}
	ft_printf("ss\n");
}
