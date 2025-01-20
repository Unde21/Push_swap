/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 00:32:33 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/20 04:52:26 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_stack *stack)
{
	t_stack	*first_elem;
	t_stack	*index;

	first_elem = stack;
	index = stack->next;
	if (stack_size(stack) == 2)
	{
		if (stack->value < stack->next->value)
			return (0);
		else
			return (-1);
	}
	while (stack->next->next != NULL)
	{
		while (index->next != NULL)
		{
			if (index->value < stack->value)
				return (-1);
			index = index->next;
		}
		stack = stack->next;
		index = stack->next;
		if (index->value < stack->value)
			return (-1);
	}
	return (0);
}

int	is_reverse_sort(t_stack *stack)
{
	t_stack	*first_elem;
	t_stack	*index;

	first_elem = stack;
	index = NULL;
	if (stack_size(stack) <= 1)
		return (0);
	index = stack->next;
	while (stack->next->next != NULL)
	{
		while (index->next != NULL)
		{
			if (index->value > stack->value)
				return (-1);
			index = index->next;
		}
		stack = stack->next;
		index = stack->next;
		if (index->value > stack->value)
			return (-1);
	}
	return (0);
}

int	get_medium_value(t_stack *stack)
{
	int	medium_value;
	int	nb_value;

	medium_value = 0;
	if (stack_size(stack) < 1)
		return (-1);
	nb_value = stack_size(stack);
	while (stack->next != NULL)
	{
		medium_value = stack->value;
		stack = stack->next;
	}
	medium_value /= nb_value;
	return (medium_value);
}
