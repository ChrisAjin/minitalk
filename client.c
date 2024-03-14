/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassa <cassassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:43:24 by cassassa          #+#    #+#             */
/*   Updated: 2024/03/12 18:02:16 by cassassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_bit(int pid, char c)
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
	int	pid;

	pid = 1;
	if (!(argc == 3))
		return (write(1, "Invalide argument!!\n", 20));
	pid = atoi(argv[1]);
	if (!(pid > 0 && pid <= PID_MAX))
		return (write(1, "Invalide argument!!\n", 20));
	while (*argv[2])
		send_bit(pid, *argv[2]++);
	return (0);
}
