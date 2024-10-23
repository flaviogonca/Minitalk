/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:48:55 by fmalungo          #+#    #+#             */
/*   Updated: 2024/09/23 12:14:29 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static bool	g_flag = false;

void	confirmation(int signo)
{
	if (signo)
		g_flag = true;
}

void	send_signal(int server_pid, char bit)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((bit >> i) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(1000);
		while (g_flag == false)
			;
		g_flag = false;
		i++;
	}
}

void	print_success(void)
{
	int	i;

	i = 6;
	ft_putstr_fd("Loading ", 1);
	while (i--)
	{
		ft_putstr_fd("\033[0;37m.\033[0;0m", 1);
		usleep(10000);
	}
	ft_putstr_fd("\033[0;32m\n\tSUCCESS\033[0;0m", 1);
}

int	main(int ac, char *av[])
{
	char	*msg;
	short	i;

	i = 0;
	msg = av[2];
	if (ac != 3)
		exit(1);
	if (ft_strlen(av[2]) == 0)
		return (0);
	while (av[1][i])
	{
		if (ft_isdigit(av[1][i]) == 0)
			exit(1);
		i++;
	}
	signal(SIGUSR1, confirmation);
	while (*msg)
	{
		send_signal(ft_atoi(av[1]), *msg);
		msg++;
	}
	send_signal(ft_atoi(av[1]), '\n');
	print_success();
	return (0);
}
