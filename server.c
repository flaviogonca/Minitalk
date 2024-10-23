/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:45:20 by fmalungo          #+#    #+#             */
/*   Updated: 2024/08/01 10:43:48 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int signal, siginfo_t *info, void *context)
{
	static pid_t	pid = 0;
	static int		c = 0;
	static int		octet = 0;

	(void)context;
	pid = info->si_pid;
	if (signal == SIGUSR1)
		c |= (1 << octet);
	octet++;
	if (octet == 8)
	{
		ft_putchar_fd(c, 1);
		c = 0;
		octet = 0;
	}
	if (pid != -1)
		kill(pid, SIGUSR1);
}

int	main(int ac, char *av[])
{
	struct sigaction	sig;
	pid_t				pid;

	(void)av;
	if (ac != 1)
		exit(1);
	pid = getpid();
	sig.sa_sigaction = sig_handler;
	sig.sa_flags = SA_SIGINFO;
	sigemptyset(&sig.sa_mask);
	ft_putstr_fd("\n\033[0;94mWELLCOME TO A CLIENT/SERVER\033[0;39m", 1);
	ft_putstr_fd("\n\n\tCOMUNICATION\n\n", 1);
	ft_putstr_fd("\033[0;95mID\033[0;39m\033[0;32m\t::", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("::\033[0;39m\n", 1);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (404)
		pause();
	return (0);
}
