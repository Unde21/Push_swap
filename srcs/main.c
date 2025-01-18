/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 04:42:01 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/18 06:37:48 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst(t_stack *stack, char c, int index)  // a retirer
{
	t_stack	*tmp;

	tmp = stack;
	if (index == 0)
	{
		ft_printf("stack : %c {", c);
		while (tmp)
		{
			ft_printf("%d -> ", tmp->value);
			tmp = tmp->next;
		}
		ft_printf("NULL");
		ft_printf("}\n");
	}
	else if (index == 1)
	{
		ft_printf("stack : %c {", c);
		while (tmp)
		{
			ft_printf("%d -> ", tmp->index);
			tmp = tmp->next;
		}
		ft_printf("NULL");
		ft_printf("}\n");
	}
	else
	{
		ft_printf("stack : %c {", c);
		while (tmp)
		{
			ft_printf("%d -> ", tmp->sort_index);
			tmp = tmp->next;
		}
		ft_printf("NULL");
		ft_printf("}\n");
	}
}
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack *stack_c;

	stack_c = NULL;
	stack_b = NULL;
	stack_a = NULL;
	if (argc == 1)
		return (0);
	if (parse_stack(argc, argv) == 0)
	{
		if (init_stack_a(argc, argv, &stack_a) != 0 || ft_lstcpy(&stack_a, &stack_c) != 0)
			return (-1);
		init_index_stackcpy(stack_c, 0);
		// print_lst(stack_a, 'a', 0);
		// print_lst(stack_b, 'b', 0);
		// push(&stack_a, &stack_b, 'b');
		// push(&stack_a, &stack_b, 'b');
		// print_lst(stack_c, 'c', 1);
		algo(&stack_c, &stack_b);
		// print_lst(stack_a, 'a', 0);
		// print_lst(stack_b, 'b', 0);
		init_index_stackcpy(stack_c, 1);
		cpy_index_sort(stack_a, stack_c);
		// ft_printf("index_sort :\n");
		// print_lst(stack_a, 'a', 0);
		// print_lst(stack_b, 'b', 0);
		sandlass_algo(stack_a, stack_b);
		// print_lst(stack_a, 'a', 0);
		// print_lst(stack_b, 'b', 0);
		//move_to_a(stack_a, stack_b);
		// print_lst(stack_c, 'c', 2);
		// ft_printf("is sort ===> %d\n", is_sort(stack_a));
		stack_clear(&stack_a, delete);
	}
	return (0);
}


void	delete(void *content)
{
	if (content)
		free(content);
}

