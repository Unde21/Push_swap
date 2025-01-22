/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandlass_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 03:58:44 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/22 04:22:55 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_chunk(int size)
{
	int	y;

	y = 0.000000053 * (size * size) + 0.03 * size + 14.5;
	return (y);
}

void	sandlass_algo(t_stack **stack_a, t_stack *stack_b, int size, int chunk)
{
	int	index;
	int	stack_index;

	index = 0;
	while (index < size)
	{
		stack_index = get_stack_top_index(*stack_a);
		if (stack_index <= index)
		{
			push(stack_a, &stack_b, 'b');
			ft_printf("pb\n");
			++index;
		}
		else if (stack_index <= index + chunk)
		{
			push(stack_a, &stack_b, 'b');
			ft_printf("pb\n");
			rotate(&stack_b, 'b');
			++index;
		}
		else
			rotate(stack_a, 'a');
	}
	move_to_a(stack_a, stack_b);
}

void	move_to_a(t_stack **stack_a, t_stack *stack_b)
{
	int	top_index;
	int	size;
	int	big_index;
	int	mid;

	big_index = 0;
	top_index = 0;
	mid = 0;
	size = stack_size(stack_b);
	while (size > 0)
	{
		top_index = get_stack_top_index(stack_b);
		big_index = find_big_index(stack_b, size);
		mid = size / 2;
		if (big_index > mid)
			while (big_index < size)
				b_reverse_rotate(&stack_b, &big_index, &top_index);
		else if (big_index <= mid)
			while (big_index > 0)
				b_rotate(&stack_b, &big_index, &top_index);
		push(stack_a, &stack_b, 'a');
		ft_printf("pa\n");
		--size;
	}
}

int	find_big_index(t_stack *stack, int size)
{
	int	big_index;

	big_index = 0;
	while (stack)
	{
		if (stack->sort_index == size - 1)
			return (big_index);
		++big_index;
		stack = stack->next;
	}
	return (-1);
}

int	get_stack_top_index(t_stack *stack)
{
	if (stack_size(stack) != 0)
		return (stack->sort_index);
	return (-1);
}
