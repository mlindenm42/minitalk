/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:02:42 by mlindenm          #+#    #+#             */
/*   Updated: 2022/08/17 16:30:36 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_printf_string(char *str)
{
	int	strlen;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	strlen = ft_strlen(str);
	if (write(1, str, strlen))
		return (strlen);
	else
		return (0);
}
