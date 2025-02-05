/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:17:54 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/21 09:18:08 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_last_index(t_stack *stack)
{
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	if (stack->sort_index == 4)
		return (1);
	return (-1);
}
