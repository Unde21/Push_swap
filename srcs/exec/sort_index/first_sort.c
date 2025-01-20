/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:51:07 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/20 04:32:07 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size_stack_a;
	int	medium;

	size_stack_a = stack_size(*stack_a);
	medium = get_medium_value(*stack_a);
	while (size_stack_a > 3)
	{
		push(stack_a, stack_b, 'b');
		size_stack_a = stack_size(*stack_a);
		if (smallest_difference(*stack_b, medium) != 0)
		{
			if (need_to_swap_b(*stack_b, 0) == 0)
				swap(stack_b);
			else
				rotate(stack_b, 'n');
		}
	}
	if (is_sort(*stack_a) != 0)
		sort_max_three(stack_a);
	recursive_sort(stack_a, stack_b);
}

void	recursive_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sort(*stack_a) == 0 && stack_size(*stack_b) == 0)
		return ;
	else if (last_is_smallest(*stack_a) > 0 && stack_size(*stack_a) > 1)
		reverse_rotate(stack_a);
	else if (first_is_biggest(*stack_a) > 0 && stack_size(*stack_a) > 1)
		rotate(stack_a, 'n');
	else if (last_is_biggest(*stack_b) > 0 && stack_size(*stack_b) > 2)
		reverse_rotate(stack_b);
	else if (first_is_smallest(*stack_b) > 0 && stack_size(*stack_b) > 2)
		rotate(stack_b, 'n');
	else if (need_to_swap(*stack_a) > 0)
		swap(stack_a);
	else if (need_to_swap(*stack_b) < 0 && stack_size(*stack_b) > 1)
		swap(stack_b);
	else if (first_is_smallest(*stack_b) > 0 && is_reverse_sort(*stack_b) != 0)
		rotate(stack_b, 'n');
	else if ((is_sort(*stack_a) != 0 && stack_size(*stack_a) > 1)
		|| (stack_size(*stack_a) > 1 && first_is_smallest(*stack_a) > 0
			&& is_sort(*stack_a) != 0))
		push(stack_a, stack_b, 'b');
	else if (stack_size(*stack_b) >= 1)
		push(stack_a, stack_b, 'a');
	recursive_sort(stack_a, stack_b);
}

void	sort_max_three(t_stack **stack_a)
{
	while (is_sort(*stack_a) != 0)
	{
		if (first_is_biggest(*stack_a) == 1)
			rotate(stack_a, 'n');
		if (need_to_swap(*stack_a) == 1 || last_is_biggest(*stack_a) != 1)
			swap(stack_a);
	}
}

int	first_is_biggest(t_stack *stack)
{
	t_stack	*first_elem;

	first_elem = stack;
	if (stack_size(stack) <= 1)
		return (1);
	while (stack->next != NULL)
	{
		stack = stack->next;
		if (first_elem->value < stack->value)
			return (-1);
	}
	return (1);
}

int	last_is_biggest(t_stack *stack)
{
	t_stack	*last_elem;

	last_elem = stack;
	if (stack_size(stack) <= 1)
		return (1);
	while (last_elem->next != NULL)
		last_elem = last_elem->next;
	while (stack->next != NULL)
	{
		if (last_elem->value < stack->value)
			return (-1);
		stack = stack->next;
	}
	return (1);
}
