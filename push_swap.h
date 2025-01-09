/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 04:52:41 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/09 05:05:34 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h> // A RETIRER
# include <stdlib.h>

// Operations

void	swap(t_list **stack, char c);
void	swap_ab (t_list **stack);
void	push (t_list **stack_a, t_list **stack_b, char c);

int	print_error(void);
int	is_integer(char *str);
int	is_duplicate(int argc, int *tab);
int	parse_stack(int argc, char **argv);

void delete (void *content);
int	init_stack_b(t_list	**stack_b);
int	init_stack_a(int argc, char **argv, t_list **stack_a);
int	add_all_number_to_stack_a(int argc, char **argv, t_list **stack_a);

#endif
