/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 04:33:05 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/07 05:00:59 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	parse_stack(int argc, char **argv)
{
	size_t i;
	int	n;

	n = 0;
	i = 0;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		if (n == -1) // voir pour set erno pour differencier -1 nb et -1 error
			return (-1);
		
	}
}
