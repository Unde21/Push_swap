/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 04:52:41 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/17 02:51:31 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h> // A RETIRER
# include <stdlib.h>
#include <stdbool.h>


typedef	struct s_stack
{
	int	value;
	int	index;
	int	sort_index;
	bool empty;
	struct s_stack *next;
	
}t_stack;

void	print_lst(t_stack *stack, char c, int index); // a retirer 
// init stack
t_stack	*new_stack(int value);
void	stack_clear(t_stack **stack, void (*del)(void *));
void	stack_add_back(t_stack **lst, t_stack *new);
int		stack_size(t_stack *stack);
void	stack_add_front(t_stack **stack, t_stack *new);
int		ft_lstcpy(t_stack **stack, t_stack **stackcpy);
void	init_index_stackcpy(t_stack *stackcpy, int index);

// Operations

void	swap(t_stack **stack, char c);
void	swap_ab (t_stack **stack_a, t_stack **stack_b);
void	push (t_stack **stack_a, t_stack **stack_b, char c);
void	rotate (t_stack **stack, char c);
void	rotate_ab (t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate (t_stack **stack, char c);
void	reverse_rotate_ab (t_stack **stack_a, t_stack **stack_b);

// algo
void	algo(t_stack **stack_a, t_stack **stack_b);
int	first_is_biggest (t_stack *stack);
int	last_is_smallest(t_stack *stack);
int	need_to_swap(t_stack *stack);
int	first_is_smallest (t_stack *stack);
int	is_sort(t_stack *stack);
int	is_reverse_sort(t_stack *stack);
int	last_is_biggest(t_stack *stack);


//version 2
void	sort_max_three(t_stack **stack_a);
void	big_sort(t_stack **stack_a, t_stack **stack_b);
int		smallest_difference(t_stack *stack, int medium_value);
int		need_to_swap_b(t_stack *stack);
int		get_medium_value(t_stack *stack);

int	print_error(void);
int	is_integer(char *str);
int	is_duplicate(int argc, int *tab);
int	parse_stack(int argc, char **argv);

void delete (void *content);
int	init_stack_b(t_stack	**stack_b);
int	init_stack_a(int argc, char **argv, t_stack **stack_a);
int	add_all_number_to_stack_a(int argc, char **argv, t_stack **stack_a);

#endif
