/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 04:42:01 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/08 04:19:22 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_lst(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		ft_printf("%d -> ", *(int *)(tmp->content));
		tmp = tmp->next;
	}
	ft_printf("NULL\n");
}

int	main(int argc, char **argv)
{
	t_list	*stack;
	int		*first_value;
	
	stack = NULL;
	if (argc == 1)
		return (0);
	if (parse_stack(argc, argv) == 0)
	{
		first_value = malloc(sizeof(int));
		if (!first_value)
			return (-2);
		*first_value = ft_atoi(argv[1]);
		stack = ft_lstnew(first_value);
		if (!stack)
		{
			free(first_value);
			return (-2);
		}
		if (init_lst(argc, argv, &stack) < 0)
		{
			ft_lstclear(&stack, delete);
			return (-1);
		}
		print_lst(stack);
		ft_lstclear(&stack, delete);
	}
	return (0);
}

void	delete(void *content)
{
	if (content)
		free(content);
}

