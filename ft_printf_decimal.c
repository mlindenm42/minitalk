/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:57:23 by mlindenm          #+#    #+#             */
/*   Updated: 2022/09/13 18:02:54 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_error(int nbr)
{
	if (nbr == -2147483648)
	{
		if (write(1, "-2147483648", 11))
			return (11);
		else
			return (-1);
	}
	if (nbr == 0)
	{
		if (write(1, "0", 1))
			return (1);
		else
			return (-1);
	}
	return (0);
}

static int	nbr_length(int nbr)
{
	int	len;

	len = 0;
	if (nbr < 0)
		nbr *= -1;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static int	print_int_array(int numbers[], int len)
{
	char	c;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (len > 0)
	{
		c = numbers[i] + '0';
		if (write(1, &c, 1))
		{
			len--;
			i++;
			count++;
		}
		else
			return (-1);
	}
	return (count);
}

int	ft_printf_decimal(int num)
{
	int	temp[10];
	int	temp_nbr;
	int	count;
	int	i;

	temp_nbr = num;
	count = check_error(num);
	i = nbr_length(num) - 1;
	if (count == 0)
	{
		if (num < 0)
		{
			write(1, "-", 1);
			count++;
			temp_nbr *= -1;
		}
		while (i >= 0)
		{
			temp[i] = temp_nbr % 10;
			temp_nbr /= 10;
			i--;
		}
		return (count + print_int_array(temp, nbr_length(num)));
	}
	return (count);
}
