/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandlass_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 03:58:44 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/18 00:46:28 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_chunk(int size)
{
	int y = 0.000000053 * (size * size) + 0.03 * size + 14.5;
    return (y);
}

void	sandlass_algo(t_stack *stack_a, t_stack *stack_b, int total_size)
{
	int	index;
	int	stack_index;
	int	chunk;

	chunk = calculate_chunk(stack_size(stack_a));
	stack_index = 0;
	index = 0;
	while (stack_size(stack_a) > 0)
	{
		print_lst(stack_a, 'a', 2);
		print_lst(stack_b, 'b', 2);
		if (stack_size(stack_a) == 1)
			break ;
		stack_index = get_stack_top_index(stack_a);
		if (stack_index <= index)
		{
			push(&stack_a, &stack_b, 'b');
			ft_printf("pa\n");
			++index;
		}
		else if (index < stack_index && stack_index <= index + chunk && stack_index != total_size)
		{
			push(&stack_a, &stack_b, 'b');
			ft_printf("pa\n");
			rotate(&stack_b, 'b');
			ft_printf("rb\n");
			++index;
		}
		else
		{
			ft_printf("last\n");
			rotate(&stack_a, 'a');
			ft_printf("ra\n");
			++index;
		}
	}
	ft_printf("after break : \n");
	print_lst(stack_a, 'a', 0);
	print_lst(stack_b, 'b', 0);
	//move_to_a(stack_a, stack_b);
}


void	move_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	value_a;
	int	value_b;

	value_a = 0;
	value_b = 0;
	ft_printf("move_to_a\n");
	while (stack_size(stack_b) > 0)
	{
		print_lst(stack_a, 'a', 0);
		print_lst(stack_b, 'b', 0);
		value_a = get_stack_top_index(stack_a);
		value_b = get_stack_top_index(stack_b);
		// ft_printf("value a %d value b %d\n", value_a, value_b);
		if (value_b < value_a)
		{
			push(&stack_a, &stack_b, 'a');
			ft_printf("pb\n");
		}
		else
		{
			rotate(&stack_b, 'b');
			ft_printf("rb\n");
		}
	}
}

int	get_stack_top_index(t_stack *stack)
{
	if (stack_size(stack) != 0)
		return (stack->sort_index);
	return (-1);
}
