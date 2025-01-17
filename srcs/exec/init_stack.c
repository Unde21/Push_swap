/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 01:46:44 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/17 02:52:44 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack_a(int argc, char **argv, t_stack **stack_a)
{
	int	first_value;

	first_value = ft_atoi(argv[1]);
	*stack_a = new_stack(first_value);
	if (!stack_a)
		return (-2);
	if (add_all_number_to_stack_a(argc, argv, stack_a) < 0)
	{
		stack_clear(stack_a, delete);
		return (-1);
	}
	return (0);
}

int	add_all_number_to_stack_a(int argc, char **argv, t_stack **stack_a)
{
	int		i;
	t_stack	*new;
	int		new_value;

	i = 2;
	while (i < argc)
	{
		if (!new_value)
			return (-1);
		new_value = ft_atoi(argv[i]);
		new = new_stack(new_value);
		if (!new)
			return (-1);
		stack_add_back(stack_a, new);
		++i;
	}
	return (0);
}

int	init_stack_b(t_stack **stack_b)
{
	*stack_b = new_stack(0);
	if (!stack_b)
		return (-2);
	return (0);
}

int	ft_lstcpy(t_stack **stack, t_stack **stackcpy)
{
	t_stack		*new;
	t_stack		*tmp;
	
	tmp = *stack;
	new = NULL;
	*stackcpy = new_stack((*stack)->value);
	if (!stackcpy)
		return (-2);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		new = new_stack(tmp->value);
		if (!new)
			return (-2);
		stack_add_back(stackcpy, new);
	}
	return (0);
}

void	init_index_stackcpy(t_stack *stackcpy, int index)
{
	int	i;

	i = 0;
	if (index == 0)
	{
		while (stackcpy->next != NULL)
		{
			stackcpy->index = i;
			stackcpy = stackcpy->next;
			++i;
		}
		stackcpy->index = i;
	}
	else
	{
		while (stackcpy->next != NULL)
		{
			stackcpy->sort_index = i;
			stackcpy = stackcpy->next;
			++i;
		}
		stackcpy->sort_index = i;
	}

}
