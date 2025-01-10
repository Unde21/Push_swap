/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 04:42:01 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/10 20:24:01 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst(t_list *lst, char c)
{
	t_list	*tmp;

	tmp = lst;
	ft_printf("stack : %c {", c);
	while (tmp)
	{
		ft_printf("%d -> ", *(int *)(tmp->content));
		tmp = tmp->next;
	}
	ft_printf("NULL");
	ft_printf("}\n");
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if (argc == 1)
		return (0);
	if (parse_stack(argc, argv) == 0)
	{
		if (init_stack_a(argc, argv, &stack_a) != 0)
			return (-1);
		print_lst(stack_a, 'a');
		print_lst(stack_b, 'b');
		swap(&stack_a, 'a');
		print_lst(stack_a, 'a');
		push(&stack_a, &stack_b, 'b');
		print_lst(stack_a, 'a');
		print_lst(stack_b, 'b');
		push(&stack_a, &stack_b, 'b');
		print_lst(stack_a, 'a');
		print_lst(stack_b, 'b');
		swap_ab(&stack_a, &stack_b);
		print_lst(stack_a, 'a');
		print_lst(stack_b, 'b');
		rotate(&stack_a, 'a');
		print_lst(stack_a, 'a');
		print_lst(stack_b, 'b');
		rotate_ab(&stack_a, &stack_b);
		print_lst(stack_a, 'a');
		print_lst(stack_b, 'b');
		reverse_rotate(&stack_a, 'a');
		print_lst(stack_a, 'a');
		print_lst(stack_b, 'b');
		reverse_rotate_ab(&stack_a, &stack_b);
		print_lst(stack_a, 'a');
		print_lst(stack_b, 'b');
		ft_lstclear(&stack_a, delete);
	}
	return (0);
}

void	delete(void *content)
{
	if (content)
		free(content);
}
