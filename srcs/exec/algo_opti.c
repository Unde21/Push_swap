/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_opti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:51:07 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/15 14:02:30 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo(t_list **stack_a, t_list **stack_b)
{
	int	size_stack_a;
	int	medium;

	size_stack_a = ft_lstsize(*stack_a);
	medium = get_medium_value(*stack_a);
	while (size_stack_a > 3)
	{
		push(stack_a, stack_b, 'b');
		size_stack_a = ft_lstsize(*stack_a);
		if (smallest_difference(*stack_b, medium) != 0)
		{
			//ft_printf("difference : %d\n", smallest_difference(*stack_b));
			// print_lst(*stack_a, 'a');
			// print_lst(*stack_b, 'b');
			if (need_to_swap_b(*stack_b) == 0)
				swap(stack_b, 'b');
			else
				rotate(stack_b, 'b');
		} 
	}
	if (is_sort(*stack_a) != 0)
		sort_max_three(stack_a);
	big_sort(stack_a, stack_b);
}

void	big_sort(t_list **stack_a, t_list **stack_b)
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
		if (need_to_swap(*stack_b) < 0 && ft_lstsize(*stack_b) > 1)
			swap_ab(stack_a, stack_b);
		//ft_printf("need_to_swap\n");
		else
			swap(stack_a, 'a');
	}
	else if (need_to_swap(*stack_b) < 0 && ft_lstsize(*stack_b) > 1)
	{
		if (need_to_swap(*stack_a) > 0)
			swap_ab(stack_a, stack_b);
		//ft_printf("need_to_swap\n");
		else
			swap(stack_b, 'b');
	}
	else if (first_is_smallest(*stack_b) > 0 && is_reverse_sort(*stack_b) != 0)
	{
		///ft_printf("second rotate\n");
		rotate(stack_b, 'b');
	}
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
	// print_lst(*stack_a, 'a');
	// print_lst(*stack_b, 'b');
	big_sort(stack_a, stack_b);
}
void	sort_max_three(t_list **stack_a)
{
	while (is_sort(*stack_a) != 0)
	{
		if (first_is_biggest(*stack_a) == 1)
			rotate(stack_a, 'a');
		if (need_to_swap(*stack_a) == 1 || last_is_biggest(*stack_a) != 1)
			swap(stack_a, 'a');
	}
}

int	first_is_biggest (t_list *stack)
{
	t_list *first_elem;

	first_elem = stack;
	if (ft_lstsize(stack) <= 1)
		return (1);
	while (stack->next != NULL)
	{
		stack = stack->next;
		if (*(int *)(first_elem->content) < *(int *)(stack->content))
			return (-1);
	}
	return (1);
}

int	last_is_biggest(t_list *stack)
{
	t_list	*last_elem;

	last_elem = stack;
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

int	need_to_swap_b(t_list *stack)
{
	t_list	*first_elem;
	t_list	*current;
	t_list	*tmp;
	int		i;
	int		j;

	tmp = stack->next;
	current = stack;
	if (ft_lstsize(stack) <= 2)
		return (-1);
	first_elem = stack;
	stack = stack->next;
	if (*(int *)(first_elem->content) < *(int *)stack->content)
	{
		i = *(int *)(stack->content) - *(int *)(tmp->content);
		if (i < 0)
			i = -i;
		while (stack->next != NULL)
		{
			stack = stack->next;
		}
		j = *(int *)(current->content) - *(int *)(stack->content);
		if (j < 0)
			j = -j;
		if (j < i)
			return (0);
		return (1);
	}
	return (0);
}
int	get_medium_value(t_list *stack)
{
	int	medium_value;
	int	nb_value;
	
	medium_value = 0;
	if (ft_lstsize(stack) < 1)
		return (-1);
	nb_value = ft_lstsize(stack);
	while (stack->next != NULL)
	{
		medium_value = *(int *)stack->content;
		stack = stack->next;
	}
	medium_value /= nb_value;
	return (medium_value);
}
int	need_to_swap(t_list *stack)
{
	t_list	*first_elem;

	if (ft_lstsize(stack) <= 1)
		return (-1);
	first_elem = stack;
	stack = stack->next;
	if (*(int *)(first_elem->content) > *(int *)stack->content)
		return (1);
	return (-1);
}

int	is_sort(t_list *stack)
{
	t_list	*first_elem;
	t_list	*index;

	first_elem = stack;
	if (ft_lstsize(stack) <= 1)
		return (0);
	index = stack->next;
	if (ft_lstsize(stack) == 2)
	{
		if (*(int *)(stack->content) < *(int *)(stack->next->content))
			return (0);
		else
			return (-1);
	}
	while (stack->next->next != NULL)
	{
		while (index->next != NULL)
		{
			if (*(int *)(index->content) < *(int *)(stack->content))
				return (-1);
			index = index->next;
		}
		stack = stack->next;
		index = stack->next;
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
int	smallest_difference(t_list *stack, int medium_value)
{
	if (*(int *)(stack->content) > medium_value)
		return (-1);
	return (0);
}
// int	smallest_difference(t_list *stack)
// {
// 	t_list	*current;
// 	t_list	*tmp;
// 	int		i;
// 	int		j;

// 	tmp = stack->next;
// 	j = 0;
// 	if (ft_lstsize(stack) <= 1)
// 		return (1);
// 	if (ft_lstsize(stack) <= 2)
// 		return (-1);
// 	i = *(int *)(stack->content) - *(int *)(tmp->content);
// 	if (i < 0)
// 		i = -i;
// 	// ft_printf("i =====> %d  and %d\n", *(int *)(stack->content), *(int *)(tmp->content));
// 	// ft_printf("i =====> %d\n", i);
// 	current = stack;
// 	while (stack->next != NULL)
// 	{
// 		stack = stack->next;
// 	}
// 	j = *(int *)(current->content) - *(int *)(stack->content);
// 	// ft_printf("next =====> %d and %d\n", *(int *)(current->content), *(int *)(stack->content));
// 	// ft_printf("j =====> %d\n", j);
// 	if (j < 0)
// 		j = -j;
// 	if (j < i)
// 		return (1);
// 	return (0);
// }
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
