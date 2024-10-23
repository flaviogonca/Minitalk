/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:48:55 by fmalungo          #+#    #+#             */
/*   Updated: 2024/08/01 11:15:52 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

int	main(int ac, char *av[])
{
	char	*msg;
	short	i;

	i = 0;
	msg = av[2];
	if (ac != 3)
		exit(1);
	if (ft_strlen(av[2]) == 0)
		exit(1);
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
	return (0);
}
