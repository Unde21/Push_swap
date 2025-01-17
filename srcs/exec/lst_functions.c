/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 01:00:29 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/18 00:19:00 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack(int value, int sort_index)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->empty = false;
	new->sort_index = sort_index;
	new->next = NULL;
	return (new);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	tmp = *stack;
	if (tmp)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*stack = new;
}

void	stack_clear(t_stack **stack, void (*delete)(void *))
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		(void)delete;
		//delete((*stack)->value);
		free(tmp);
		*stack = tmp;
	}
	stack = NULL;
}

int	stack_size(t_stack *stack)
{
	int		size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		++size;
	}
	return (size);
}

void	stack_add_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

// t_stackcpy	*new_stackcpy(int value)
// {
// 	t_stackcpy	*new;

// 	new = malloc(sizeof(t_stackcpy));
// 	if (!new)
// 		return (NULL);
// 	new->value = value;
// 	new->empty = false;
// 	new->next = NULL;
// 	return (new);
// }

// void	stack_add_backcpy(t_stackcpy **stack, t_stackcpy *new)
// {
// 	t_stackcpy	*tmp;

// 	tmp = *stack;
// 	if (tmp)
// 	{
// 		while (tmp->next != NULL)
// 			tmp = tmp->next;
// 		tmp->next = new;
// 	}
// 	else
// 		*stack = new;
// }
