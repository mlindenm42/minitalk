/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:52:50 by mlindenm          #+#    #+#             */
/*   Updated: 2023/10/16 04:19:11 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "ft_printf.h"
#include <stdlib.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 7 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i > 0 && str[i - 1] == '-')
		sign = -1;
	while (ft_isdigit(str[i]))
	{
		if (res * sign > 2147483647)
			return (-1);
		if (res * sign < -2147483648)
			return (0);
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (sign * res);
}

void	send_character(pid_t server_pid, char c)
{
	long	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;
	char	*string;
	int		i;

	if (argc != 3)
	{
		ft_printf("Usage: %s <server-pid> <string>\n", argv[0]);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_printf("Error Server-PID wrong: %d\n", server_pid);
		return (1);
	}
	i = 0;
	string = argv[2];
	while (string[i] != '\0')
	{
		send_character(server_pid, string[i]);
		i++;
	}
	send_character(server_pid, '\0');
	return (0);
}
