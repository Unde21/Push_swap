/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:13:00 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/18 05:04:13 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate (t_stack **stack, char c)
{
	t_stack	*first_elem;
	
	(void)c; // a retirer
	first_elem = *stack;
	if (stack_size(*stack) > 1)
	{	
		*stack = first_elem->next;
		stack_add_back(stack, first_elem);
		first_elem->next = NULL;
		// ft_printf("r%c\n", c);
	}
}

void	rotate_ab (t_stack **stack_a, t_stack **stack_b)   // a revoir pour l affichage rr si une des 2 conditions n est pas rempli
{
	t_stack	*first_elem;
	
	first_elem = *stack_a;
	if (stack_size(*stack_a) > 1 && first_elem->empty != true)
	{	
		*stack_a = first_elem->next;
		stack_add_back(stack_a, first_elem);
		first_elem->next = NULL;
	}
	first_elem = *stack_b;
	if (stack_size(*stack_b) > 1 && first_elem->empty != true)
	{	
		*stack_b = first_elem->next;
		stack_add_back(stack_b, first_elem);
		first_elem->next = NULL;
	}
	// ft_printf("rr\n");
}


// // Fonction qui déplace les éléments de stack_b vers stack_a
// void move_to_a(t_stack *stack_a, t_stack *stack_b)
// {
//     int value_a;
//     int value_b;
//     int stack_b_size;

//     ft_printf("move_to_a\n");

//     while (stack_size(stack_b) > 0)  // Tant que stack_b n'est pas vide
//     {
//         // Afficher l'état actuel des piles
//         print_lst(stack_a, 'a', 0);
//         print_lst(stack_b, 'b', 0);

//         // Récupérer les valeurs du sommet des piles
//         value_a = get_stack_top_index(stack_a);
//         value_b = get_stack_top_index(stack_b);

//         ft_printf("value_a: %d, value_b: %d\n", value_a, value_b);

//         // Si la valeur de stack_b est plus petite que celle de stack_a
//         if (value_b < value_a)
//         {
//             push(&stack_a, &stack_b, 'a');  // Transférer de b vers a
//             ft_printf("pb\n");
//         }
//         else
//         {
//             // Si la valeur de stack_b est plus grande, on fait tourner stack_b
//             stack_b_size = stack_size(stack_b);
//             if (value_b > value_a && stack_b_size > 1)
//             {
//                 // Si l'élément est dans la partie supérieure de stack_b, utiliser reverse rotate
//                 if (stack_b_size / 2 < get_position(stack_b, value_b))
//                 {
//                     reverse_rotate(&stack_b, 'b');
//                     ft_printf("rrb\n");
//                 }
//                 else
//                 {
//                     rotate(&stack_b, 'b');
//                     ft_printf("rb\n");
//                 }
//             }
//             else
//             {
//                 // Effectuer une rotation si nécessaire
//                 rotate(&stack_b, 'b');
//                 ft_printf("rb\n");
//             }
//         }
//     }
// }
