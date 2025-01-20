/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 00:22:31 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/20 04:32:15 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first_is_smallest(t_stack *stack)
{
	t_stack	*first_elem;

	first_elem = stack;
	if (stack_size(stack) <= 1)
		return (1);
	while (stack->next != NULL)
	{
		if (first_elem->value > stack->value)
			return (-1);
		stack = stack->next;
	}
	return (1);
}

int	last_is_smallest(t_stack *stack)
{
	t_stack	*last_elem;

	last_elem = stack;
	if (stack_size(stack) <= 1)
		return (1);
	while (last_elem->next != NULL)
		last_elem = last_elem->next;
	while (stack->next != NULL)
	{
		if (last_elem->value > stack->value)
			return (-1);
		stack = stack->next;
	}
	return (1);
}

int	smallest_difference(t_stack *stack, int medium_value)
{
	if (stack->value > medium_value)
		return (-1);
	return (0);
}

int	need_to_swap(t_stack *stack)
{
	t_stack	*first_elem;

	if (stack_size(stack) <= 1)
		return (-1);
	first_elem = stack;
	stack = stack->next;
	if (first_elem->value > stack->value)
		return (1);
	return (-1);
}

int	need_to_swap_b(t_stack *stack, int i)
{
	t_stack	*first_elem;
	t_stack	*current;
	t_stack	*tmp;
	int		j;

	tmp = stack->next;
	current = stack;
	if (stack_size(stack) <= 2)
		return (-1);
	first_elem = stack;
	stack = stack->next;
	if (first_elem->value < stack->value)
	{
		i = stack->value - tmp->value;
		if (i < 0)
			i = -i;
		while (stack->next != NULL)
			stack = stack->next;
		j = current->value - stack->value;
		if (j < 0)
			j = -j;
		if (j > i)
			return (1);
	}
	return (0);
}
