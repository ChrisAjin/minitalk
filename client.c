/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassa <cassassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:43:24 by cassassa          #+#    #+#             */
/*   Updated: 2024/03/08 18:34:09 by cassassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	i;
	int	shift;
	int	pid;

	i = -1;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0 || pid > PID_MAX)
		{
			write(1, "Invalide pID\n", 12);
			return (1);
		}
		while (argv[2][++i])
		{
			shift = 8;
			while (shift-- > 0)
			{
				if ((argv[2][i] >> shift) & 1)
					kill(pid, SIGUSR1);
				else
					kill(pid, SIGUSR2);
				usleep(30);
			}
		}
	}
	else
		write(1, "invalide argument!!\n", 20);
}
