/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 01:21:23 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/09 01:53:57 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap (t_list **stack, char c)
{
	t_list	*first_elem;
	t_list	*second_elem;
	void	*swap;

	first_elem = *stack;
	second_elem = first_elem->next;
	if (second_elem->next != NULL)
	{
		swap = first_elem->content;
		first_elem->content = second_elem->content;
		second_elem->content = swap;
	}
	ft_printf("s%c\n", c);
}

void	push (t_list **stack_a, t_list **stack_b, char c)
{
	t_list	*first_elem_a;
	t_list	*first_elem_b;
	t_list	*new;

	first_elem_a = *stack_a;
	first_elem_b = *stack_b;
	if (c == 'a' && first_elem_b->content != NULL)
	{
			new = ft_lstnew(first_elem_b->content);
			ft_lstadd_front(stack_a, new);
			ft_lstdelone(*stack_b, delete);
	}
	else if (c == 'b' && first_elem_a->content != NULL)
	{
		new = ft_lstnew(first_elem_a->content);
		ft_lstadd_front(stack_b, new);
		ft_lstdelone(*stack_a, delete);
	}
}
