/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 01:46:44 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/08 04:42:57 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	init_lst(int argc, char **argv, t_list **stack)
{
	int	i;
	t_list *new;
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
		ft_lstadd_back(stack, new);
		++i;
	}
	return (0);
}
