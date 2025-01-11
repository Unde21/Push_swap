/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:12:32 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/11 01:25:49 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push (t_list **stack_a, t_list **stack_b, char c)
{
	t_list	*first_elem_a;
	t_list	*first_elem_b;
	t_list	*new;

	new = NULL;
	first_elem_a = *stack_a;
	first_elem_b = *stack_b;
	if (c == 'a' && first_elem_b->content != NULL)
	{
		new = ft_lstnew(first_elem_b->content);
		if (!new)
			return ;
		ft_lstadd_front(stack_a, new);
		if (ft_lstsize(*stack_b) > 1)
			*stack_b = first_elem_b->next;
		else
			*stack_b = NULL;
		ft_printf("p%c\n", c);
		free(first_elem_b);
	}
	else if (c == 'b' && first_elem_a->content != NULL)
	{
		new = ft_lstnew(first_elem_a->content);
		if (!new)
			return ;
		ft_lstadd_front(stack_b, new);
		if (ft_lstsize(*stack_a) > 1)
			*stack_a = first_elem_a->next;
		else
			*stack_b = NULL;
		ft_printf("p%c\n", c);
		free(first_elem_a);
	}
}
