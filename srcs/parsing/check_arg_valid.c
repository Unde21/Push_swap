/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 04:33:05 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/05 21:43:16 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	parse_stack(int argc, char **argv)
{
	int	i;
	int	*tmp_int;

	i = 1;
	tmp_int = ft_calloc(sizeof(int), argc - 1);
	if (!tmp_int)
		return (-2);
	while (i < argc)
	{
		if (is_integer(argv[i]) < 0 || argv[i][0] == '\0')
		{
			free(tmp_int);
			return (print_error());
		}
		if (check_error_atoi(tmp_int, i, argv) != 0)
			return (print_error());
		++i;
	}
	if (is_duplicate(argc, tmp_int) < 0)
	{
		free(tmp_int);
		return (print_error());
	}
	free(tmp_int);
	return (0);
}

int	is_integer(char *str)
{
	size_t	i;
	size_t	size_max_int;

	size_max_int = 10;
	i = 0;
	if (str[i] == '-')
	{
		i++;
		size_max_int += 1;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9'
			|| (ft_strlen(str) == 10 && str[i + 1] == '\0' && str[i] > '7'))
			return (-1);
		++i;
	}
	if (i > size_max_int)
		return (-1);
	return (0);
}

int	is_duplicate(int argc, int *tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		while (j < argc - 1)
		{
			if (tab[i] == tab[j] && j != i)
				return (-1);
			++j;
		}
		++i;
	}
	return (0);
}

int	check_error_atoi(int *tmp_int, int i, char **argv)
{
	int	len_nb;

	len_nb = ft_strlen(argv[i]);
	if (len_nb >= 11 && (argv[i][0] == '-' || argv[i][0] == '+')
		&& argv[i][len_nb - 1] > '8')
	{
		free(tmp_int);
		return (-1);
	}
	if ((len_nb == 1 && argv[i][0] == '-') || (argv[i][0] == '+'
			&& len_nb == 1))
	{
		free(tmp_int);
		return (-1);
	}
	tmp_int[i - 1] = ft_atoi(argv[i]);
	return (0);
}
