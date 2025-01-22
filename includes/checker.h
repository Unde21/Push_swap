/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:35:13 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/22 01:16:49 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "push_swap.h"


typedef struct s_stack_check
{
	int	value;
	struct s_stack_check *next;
} t_stack_check;

void	get_input(t_stack **stack_a, t_stack **stack_b);
int		execute_input(t_stack **stack_a, t_stack **stack_b, char *line);

#endif
