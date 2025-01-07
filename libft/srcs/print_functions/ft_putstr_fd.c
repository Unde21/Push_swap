/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:32:34 by samaouch          #+#    #+#             */
/*   Updated: 2025/01/07 03:47:28 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	const size_t	len_s = ft_strlen(s);

	write(fd, s, len_s);
}
