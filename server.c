/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:53:29 by mlindenm          #+#    #+#             */
/*   Updated: 2023/10/16 04:54:40 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "ft_printf.h"

int		g_i = 0;

static void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (s);
}

static void	handler_sigusr(int sig, siginfo_t *sinfo, void *ptr)
{
	static int	bit_count = 0;
	static char	byte = 0;

	if (sig == SIGUSR1)
		byte |= (1 << bit_count);
	(void) ptr;
	bit_count++;
	if (bit_count == 8)
	{
		if (byte == '\0')
		{
			write(1, "\n", 1);
			kill(sinfo->si_pid, SIGUSR1);
			g_i = 0;
		}
		else
		{
			write(1, &byte, 1);
			g_i++;
		}
		byte = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_sigaction = &handler_sigusr;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
