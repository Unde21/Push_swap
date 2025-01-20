/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 01:46:44 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/20 01:00:38 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack_a(int argc, char **argv, t_stack **stack_a)
{
	int	first_value;

	first_value = ft_atoi(argv[1]);
	*stack_a = new_stack(first_value, 0);
	if (!stack_a)
		return (-2);
	if (add_all_number_to_stack_a(argc, argv, stack_a) < 0)
		return (-1);
	return (0);
}

int	add_all_number_to_stack_a(int argc, char **argv, t_stack **stack_a)
{
	int		i;
	t_stack	*new;
	int		new_value;

	new_value = 0;
	i = 2;
	while (i < argc)
	{
		new_value = ft_atoi(argv[i]);
		new = new_stack(new_value, 0);
		if (!new)
			return (-1);
		stack_add_back(stack_a, new);
		++i;
	}
	return (0);
}

int	init_stack_b(t_stack **stack_b)
{
	*stack_b = new_stack(0, 0);
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
	*stackcpy = new_stack((*stack)->value, (*stack)->sort_index);
	if (!stackcpy)
		return (-2);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		new = new_stack(tmp->value, tmp->sort_index);
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

void	cpy_index_sort(t_stack *stack_a, t_stack *stack_c)
{
	t_stack	*tmp;
	
	tmp = stack_a;
	while (stack_c)
	{
		while (tmp)
		{
			if (stack_c->value == tmp->value)
			{
				tmp->sort_index = stack_c->sort_index;
				break ;
			}
			tmp = tmp->next;	
		}
		tmp = stack_a;
		stack_c = stack_c->next;
	}
}

