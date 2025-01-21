/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 04:45:06 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/21 09:20:53 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		first_number;
	t_stack	*elem;

	elem = *stack_a;
	first_number = 0;
	if (size <= 3)
		sort_three(stack_a);
	if (size == 5 || size == 4)
	{
		while (elem->sort_index != 0)
		{
			++first_number;
			elem = elem->next;
		}
		if (size == 5)
		{
			sort_five(stack_a, stack_b, first_number);
			push(stack_a, stack_b, 'a');
			ft_printf("pa\n");
		}
		else
			sort_four(stack_a, stack_b, first_number);
		push(stack_a, stack_b, 'a');
		ft_printf("pa\n");
	}
}

void	sort_three(t_stack **stack_a)
{
	while (is_sort(*stack_a) != 0)
	{
		if (first_is_biggest(*stack_a) == 1)
			rotate(stack_a, 'a');
		if (need_to_swap(*stack_a) == 1 || last_is_biggest(*stack_a) != 1)
		{
			swap(stack_a);
			ft_printf("sa\n");
		}
	}
}

void	sort_five(t_stack **stack_a, t_stack **stack_b, int first_number)
{
	if (first_number > 2)
	{
		while ((*stack_a)->sort_index != 0)
		{
			reverse_rotate(stack_a);
			ft_printf("rra\n");
		}
	}
	else if (first_number <= 2)
	{
		while ((*stack_a)->sort_index != 0)
			rotate(stack_a, 'a');
	}
	push_and_print_b(stack_a, stack_b);
	while ((*stack_a)->sort_index != 1)
		rotate(stack_a, 'a');
	push_and_print_b(stack_a, stack_b);
	while (get_last_index(*stack_a) != 1)
		rotate(stack_a, 'a');
	if (is_sort(*stack_a) != 0)
	{
		swap(stack_a);
		ft_printf("sa\n");
	}
}

void	sort_four(t_stack **stack_a, t_stack **stack_b, int first_number)
{
	if (first_number > 2)
	{
		while ((*stack_a)->sort_index != 0)
		{
			reverse_rotate(stack_a);
			ft_printf("rra\n");
		}
	}
	if (is_sort(*stack_a) == 0)
		return ;
	else if (first_number <= 2)
	{
		while ((*stack_a)->sort_index != 0)
			rotate(stack_a, 'a');
	}
	if (is_sort(*stack_a) == 0)
		return ;
	push_and_print_b(stack_a, stack_b);
	sort_three(stack_a);
}

void	push_and_print_b(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b, 'b');
	ft_printf("pb\n");
}
