/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassa <cassassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:43:24 by cassassa          #+#    #+#             */
/*   Updated: 2024/03/12 17:06:41 by cassassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler(int signum)
{
	if (signum == SIGUSR1)
		write(1, "message recu\n", 14);
}

void	send_character(char c, int pid)
{
	int	shift;

	shift = 8;
	while (shift-- > 0)
	{
		if ((c >> shift) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(30);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = -1;
	signal(SIGUSR1, &handler);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (!(argc == 3 && pid > 0 && pid <= PID_MAX))
			return (write(1, "Invalide PID!!\n", 15));
		while (argv[2][++i])
			send_character(argv[2][i], pid);
		send_character('\0', pid);
	}
	else
		write(1, "invalide argument!!\n", 20);
	return (0);
}
