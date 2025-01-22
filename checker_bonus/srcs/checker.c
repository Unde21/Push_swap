/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:34:52 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/22 01:16:18 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc < 2)
		return (0);
	if (parse_stack(argc, argv) == 0)
	{
		if (init_stack_a(argc, argv, &stack_a) != 0)
		{
			stack_clear(&stack_a);
			return (-1);
		}
		get_input(&stack_a, &stack_b);
		stack_clear(&stack_a);
	}
	return (0);
}

void	get_input(t_stack **stack_a, t_stack **stack_b)
{
	char *line;

	line = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break;
		if (line)
		{
			if (execute_input(stack_a, stack_b, line) == -1)
			{
				free(line);
				print_error();
				return ;
			}
			if (is_sort(*stack_a) != 0 || stack_b != NULL)
				ft_printf("KO\n");
			else
				ft_printf("OK\n");
			free(line);
			line = NULL;
		}
	}
}

int	execute_input(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		swap(stack_a);
	else if (ft_strcmp(line, "sb\n") == 0)
		swap(stack_b);
	else if (ft_strcmp(line, "ss\n") == 0)
		swap_ab(stack_a, stack_b);
	else if (ft_strcmp(line, "pa\n") == 0)
		push(stack_a, stack_b, 'a');
	else if (ft_strcmp(line, "pb\n") == 0)
		push(stack_a, stack_b, 'b');
	else if (ft_strcmp(line, "ra\n") == 0)
		rotate(stack_a, 'n');
	else if (ft_strcmp(line, "rb\n") == 0)
		rotate(stack_b, 'n');
	else if (ft_strcmp(line, "rr\n") == 0)
		rotate_ab(stack_a, stack_b);
	else if (ft_strcmp(line, "rra\n") == 0)
		reverse_rotate(stack_a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		reverse_rotate(stack_b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		reverse_rotate_ab(stack_a, stack_b);
	else
		return (-1);
	return (0);
}
