/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandlass_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 03:58:44 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/18 07:09:58 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_chunk(int size)
{
	int y = 0.000000053 * (size * size) + 0.03 * size + 14.5;
    return (y);
}

void	sandlass_algo(t_stack *stack_a, t_stack *stack_b)
{
	int	index;
	int	stack_index;
	int	chunk;
	int	size;

	size = stack_size(stack_a);
	// print_lst(stack_a, 'a', 0);
	chunk = calculate_chunk(stack_size(stack_a));
	stack_index = 0;
	index = 0;
	while (index < size)
	{
		// print_lst(stack_a, 'a', 0);
		// print_lst(stack_b, 'b', 0);
		// print_lst(stack_a, 'a', 2);
		// print_lst(stack_b, 'b', 2);
		// if (stack_size(stack_a) == 1)
		// 	break ;
		stack_index = get_stack_top_index(stack_a);
		if (stack_index <= index)
		{
			push(&stack_a, &stack_b, 'b');
			ft_printf("pb\n");
			// if (need_to_swap_b(stack_b) == 1)
			// 	swap(&stack_b, 'b');
			++index;
		}
		else if (stack_index <= index + chunk)
		{
			push(&stack_a, &stack_b, 'b');
			ft_printf("pb\n");
			rotate(&stack_b, 'b');
			if (stack_size(stack_b) > 1)
				ft_printf("rb\n");
			++index;
		}
		else
		{
			// ft_printf("last\n");
			rotate(&stack_a, 'a');
			ft_printf("ra\n");
			// ++index;
		}
	}
	// ft_printf("after break : \n");
	print_lst(stack_a, 'a', 0);
	print_lst(stack_b, 'b', 0);
	move_to_a(stack_a, stack_b);
}


void	move_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	top_index;
	int	size;
	int	big_index;
	int	mid;

	
	big_index = 0;
	top_index = 0;
	mid = 0;
	print_lst(stack_a, 'a', 0);
	print_lst(stack_b, 'b', 0);
	size = stack_size(stack_b);
	ft_printf("size : %d\n", size);
	while (size > 0)
	{
		top_index = get_stack_top_index(stack_b);
		ft_printf("top index : %d\n", top_index);
		big_index = find_big_index(stack_b, size);
		ft_printf("big : %d\n", big_index);
		mid = size / 2;
		if (big_index > mid)
			while (big_index < size)
			{
				b_reverse_rotate(&stack_b, &big_index, &top_index);
				print_lst(stack_a, 'a', 0);
				print_lst(stack_b, 'b', 0);
			}
		else if (big_index <= mid)
			while (big_index > 0)
			{
				b_rotate(stack_b, &big_index, &top_index);
				print_lst(stack_a, 'a', 0);
				print_lst(stack_b, 'b', 0);
			}
		print_lst(stack_a, 'a', 0);
		push(&stack_a, &stack_b, 'a');
		ft_printf("pa\n");
		--size;
		print_lst(stack_a, 'a', 0);
		print_lst(stack_b, 'b', 0);
	}
}

void	b_rotate(t_stack *stack_b, int *pos, int *top_index)
{
	rotate(&stack_b, 'b');
	ft_printf("rb\n");
	*top_index = stack_b->sort_index;
	(*pos)--;
}
void	b_reverse_rotate(t_stack *stack_b, int *pos, int *top_index)
{
	reverse_rotate(&stack_b, 'b');
	ft_printf("rrb\n");
	// ft_printf("top rrrr index : %d\n", *top_index);
	*top_index = stack_b->sort_index;
	// ft_printf("top  rrrrindex : %d\n", *top_index);
	(*pos)++;
}

int	find_big_index(t_stack *stack, int size)
{
	int big_index;

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
