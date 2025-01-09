/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 01:46:44 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/09 01:44:58 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack_a(int argc, char **argv, t_list **stack_a)
{
	int	*first_value;

	first_value = malloc(sizeof(int));
	if (!first_value)
		return (-2);
	*first_value = ft_atoi(argv[1]);
	*stack_a = ft_lstnew(first_value);
	if (!stack_a)
	{
		free(first_value);
		return (-2);
	}
	if (add_all_number_to_stack_a(argc, argv, stack_a) < 0)
	{
		ft_lstclear(stack_a, delete);
		return (-1);
	}
	return (0);
}

int	add_all_number_to_stack_a(int argc, char **argv, t_list **stack_a)
{
	int		i;
	t_list	*new;
	int		*new_value;

	i = 2;
	while (i < argc)
	{
		new_value = malloc(sizeof(int));
		if (!new_value)
			return (-1);
		*new_value = ft_atoi(argv[i]);
		new = ft_lstnew(new_value);
		if (!new)
		{
			free(new_value);
			return (-1);
		}
		ft_lstadd_back(stack_a, new);
		++i;
	}
	return (0);
}

int	init_stack_b(t_list	**stack_b)
{
	*stack_b = ft_lstnew(NULL);
	if (!stack_b)
		return (-2);
	return (0);
}
