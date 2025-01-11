/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:50:28 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/11 02:39:18 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo(t_list **stack_a, t_list **stack_b)
{
	//ft_printf("before break\n");
	if (is_sort(*stack_a) == 0 && ft_lstsize(*stack_b) == 0)
		return ;
	else if (last_is_smallest(*stack_a) > 0 && ft_lstsize(*stack_a) > 1)
	{
		// ft_printf("first is bigget => %d  lstsize = %d\n", first_is_biggest(*stack_b) ,ft_lstsize(*stack_b));
		//ft_printf("reverse_rotate segfault\n");
		if (last_is_biggest(*stack_b) > 0 && ft_lstsize(*stack_b) > 2)
			reverse_rotate_ab(stack_a, stack_b);
		else
			reverse_rotate(stack_a, 'a');
	}
	else if (first_is_biggest(*stack_a) > 0 && ft_lstsize(*stack_a) > 1)
	{
		//ft_printf("is_bigger > 0\n");
		if (first_is_smallest(*stack_b) > 0 && ft_lstsize(*stack_b) > 2)
			rotate_ab(stack_a, stack_b);
		else
			rotate(stack_a, 'a');
		//ft_printf("after_rotate\n");
	}
	else if (last_is_biggest(*stack_b) > 0 && ft_lstsize(*stack_b) > 2)
	{
		// ft_printf("first is bigget => %d  lstsize = %d\n", first_is_biggest(*stack_b) ,ft_lstsize(*stack_b));
		//ft_printf("reverse_rotate segfault\n");
		if (last_is_smallest(*stack_a) > 0 && ft_lstsize(*stack_a) > 1)
			reverse_rotate_ab(stack_a, stack_b);
		else
			reverse_rotate(stack_b, 'b');
	}
	else if (first_is_smallest(*stack_b) > 0 && ft_lstsize(*stack_b) > 2)
	{
		//ft_printf("is_bigger > 0\n");
		if (first_is_biggest(*stack_a) > 0 && ft_lstsize(*stack_a) > 1)
			rotate_ab(stack_a, stack_b);
		else
			rotate(stack_b, 'b');
		//ft_printf("after_rotate\n");
	}
	else if (need_to_swap(*stack_a) > 0)
	{
		//ft_printf("need_to_swap\n");
		if (need_to_swap(*stack_b) < 0 && ft_lstsize(*stack_b) > 1)
			swap_ab(stack_a, stack_b);
		else
			swap(stack_a, 'a');
	}
	else if (need_to_swap(*stack_b) < 0 && ft_lstsize(*stack_b) > 1)
	{
		//ft_printf("need_to_swap\n");
		if (need_to_swap(*stack_a) > 0)
			swap_ab(stack_a, stack_b);
		else
			swap(stack_b, 'b');
	}
	// else if (first_is_smallest(*stack_b) > 0 && is_reverse_sort(*stack_b) != 0)
	// {
	// 	///ft_printf("second rotate\n");
	// 	rotate(stack_b, 'b');
	// }
	else if ((is_sort(*stack_a) != 0  && ft_lstsize(*stack_a) > 1)
		|| (ft_lstsize(*stack_a) > 1 &&  first_is_smallest(*stack_a) > 0 && is_sort(*stack_a) != 0))
	{
		//ft_printf("pushing me away\n");
		push(stack_a, stack_b, 'b');
	}
	else if (ft_lstsize(*stack_b) >= 1)
	{
		// ft_printf("second push\n");
		push(stack_a, stack_b, 'a');
		//ft_printf("after second push\n");
	}
	//  print_lst(*stack_a, 'a');
	//  print_lst(*stack_b, 'b');
	algo(stack_a, stack_b);
}

int	first_is_biggest (t_list *stack)
{
	t_list *first_elem;

	first_elem = stack;
	//ft_printf("first_is_bigger\n");
	if (ft_lstsize(stack) <= 1)
		return (1);
	//print_lst(stack, 'c');
	while (stack->next != NULL)
	{
		stack = stack->next;
		//ft_printf("first elem ==> %d, compare %d\n", *(int *)(first_elem->content), *(int *)(stack->content));
		if (*(int *)(first_elem->content) < *(int *)(stack->content))
			return (-1);
	}
	return (1);
}

int	last_is_smallest(t_list *stack)
{
	t_list	*last_elem;

	last_elem = stack;
	//ft_printf("last_is_small\n");
	if (ft_lstsize(stack) <= 1)
		return (1);
	while (last_elem->next != NULL)
		last_elem = last_elem->next;
	while (stack->next != NULL)
	{
		if (*(int *)(last_elem->content) > *(int *)(stack->content))
			return (-1);
		stack = stack->next;
	}
	return (1);
}

int	last_is_biggest(t_list *stack)
{
	t_list	*last_elem;

	last_elem = stack;
	//ft_printf("last_is_small\n");
	if (ft_lstsize(stack) <= 1)
		return (1);
	while (last_elem->next != NULL)
		last_elem = last_elem->next;
	while (stack->next != NULL)
	{
		if (*(int *)(last_elem->content) < *(int *)(stack->content))
			return (-1);
		stack = stack->next;
	}
	return (1);
}

int	need_to_swap(t_list *stack)
{
	t_list	*first_elem;

	//ft_printf("need_to_swap\n");
	if (ft_lstsize(stack) <= 1)
		return (-1);
	first_elem = stack;
	stack = stack->next;
	if (*(int *)(first_elem->content) > *(int *)stack->content)
		return (1);
	return (-1);
}

int	first_is_smallest (t_list *stack)
{
	t_list *first_elem;

	first_elem = stack;
	//ft_printf("first_is_smallest\n");
	if (ft_lstsize(stack) <= 1)
		return (1);
	while (stack->next != NULL)
	{
		if (*(int *)(first_elem->content) > *(int *)(stack->content))
			return (-1);
		stack = stack->next;
	}
	return (1);
}

int	is_sort(t_list *stack)
{
	t_list	*first_elem;
	t_list	*index;

	first_elem = stack;
	index = NULL;
	//ft_printf("is_sort\n");
	if (ft_lstsize(stack) <= 1)
		return (0);
	index = stack->next;
	while (stack->next->next != NULL)
	{
		while (index->next != NULL)
		{
			// ft_printf("index ==> %d, compare %d\n", *(int *)(index->content), *(int *)(stack->content));
			if (*(int *)(index->content) < *(int *)(stack->content))
				return (-1);
			index = index->next;
		}
		stack = stack->next;
		index = stack->next;
		// ft_printf("index ==> %d, compare %d\n", *(int *)(index->content), *(int *)(stack->content));
		if (*(int *)(index->content) < *(int *)(stack->content))
				return (-1);
	}
	return (0);
}

int	is_reverse_sort(t_list *stack)
{
	t_list	*first_elem;
	t_list	*index;

	first_elem = stack;
	index = NULL;
	//ft_printf("is_reverse_sort\n");
	if (ft_lstsize(stack) <= 1)
		return (0);
	index = stack->next;
	while (stack->next->next != NULL)
	{
		while (index->next != NULL)
		{
			// ft_printf("index ==> %d, compare %d\n", *(int *)(index->content), *(int *)(stack->content));
			if (*(int *)(index->content) > *(int *)(stack->content))
				return (-1);
			index = index->next;
		}
		stack = stack->next;
		index = stack->next;
		// ft_printf("index ==> %d, compare %d\n", *(int *)(index->content), *(int *)(stack->content));
		if (*(int *)(index->content) > *(int *)(stack->content))
				return (-1);
	}
	return (0);
}
