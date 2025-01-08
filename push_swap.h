/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 04:52:41 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/08 04:23:04 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h> // A RETIRER

# include "libft/libft.h"
# include <stdlib.h>

int	print_error(void);
int	is_integer(char *str);
int	is_duplicate(int *tab);
int	parse_stack(int argc, char **argv);


void	delete(void *content);
int	init_lst(int argc, char **argv, t_list **stack);

#endif
