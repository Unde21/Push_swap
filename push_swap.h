/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 04:52:41 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/20 06:08:46 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdbool.h>



typedef struct s_stack
{
	int				value;
	int				index;
	int				sort_index;
	bool			empty;
	struct s_stack	*next;
}	t_stack;

// void	printf_lst(t_stack *stack);
/* ************************************************************************** */
/*								Sandlass algo								  */
/* ************************************************************************** */
void	sandlass_algo(t_stack **stack_a, t_stack *stack_b, int size, int chunk);
void	sort_three(t_stack *stack_a);
int		get_last_index(t_stack *stack);
void	sort_five(t_stack **stack_a, t_stack *stack_b, int first_number);
void	small_sort(t_stack **stack_a, t_stack *stack_b, int size);
void	run(t_stack **stack_a, t_stack *stack_b, t_stack *stack_c);
void	move_to_a(t_stack **stack_a, t_stack *stack_b);
void	b_rotate(t_stack **stack_b, int *pos, int *top_index);
void	b_reverse_rotate(t_stack **stack_b, int *pos, int *top_index);
int		get_stack_top_index(t_stack *stack);
int		get_position(t_stack *stack, int value);
int		find_big_index(t_stack *stack, int size);
int		calculate_chunk(int size);

/* ************************************************************************** */
/*								Lst functions								  */
/* ************************************************************************** */
void	stack_clear(t_stack **stack);
void	stack_add_front(t_stack **stack, t_stack *new);
void	stack_add_back(t_stack **lst, t_stack *new);
void	init_index_stackcpy(t_stack *stackcpy, int index);
void	cpy_index_sort(t_stack *stack_a, t_stack *stack_c);
t_stack	*new_stack(int value, int sort_index);
int		stack_size(t_stack *stack);
int		ft_lstcpy(t_stack **stack, t_stack **stackcpy);

/* ************************************************************************** */
/*								Operations								  	  */
/* ************************************************************************** */
void	swap(t_stack **stack);
void	swap_ab(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack, char c);
void	rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate(t_stack **stack);
void	reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **stack_a, t_stack **stack_b, char c);

/* ************************************************************************** */
/*								First_sort								  	  */
/* ************************************************************************** */
void	sort_max_three(t_stack **stack_a);
void	recursive_sort(t_stack **stack_a, t_stack **stack_b);
void	first_sort(t_stack **stack_a, t_stack **stack_b);
int		smallest_difference(t_stack *stack, int medium_value);
int		need_to_swap(t_stack *stack);
int		need_to_swap_b(t_stack *stack, int i);
int		last_is_smallest(t_stack *stack);
int		last_is_biggest(t_stack *stack);
int		is_sort(t_stack *stack);
int		is_reverse_sort(t_stack *stack);
int		get_medium_value(t_stack *stack);
int		first_is_smallest(t_stack *stack);
int		first_is_biggest(t_stack *stack);

/* ************************************************************************** */
/*								Parsing									  	  */
/* ************************************************************************** */
int		print_error(void);
int		parse_stack(int argc, char **argv);
int		is_integer(char *str);
int		is_duplicate(int argc, int *tab);

/* ************************************************************************** */
/*								Init stack								  	  */
/* ************************************************************************** */
int		init_stack_b(t_stack	**stack_b);
int		init_stack_a(int argc, char **argv, t_stack **stack_a);
// int		add_all_number_to_stack_a(int argc, char **argv, t_stack **stack_a);

#endif
