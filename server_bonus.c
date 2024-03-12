/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassa <cassassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:43:21 by cassassa          #+#    #+#             */
/*   Updated: 2024/03/12 15:45:36 by cassassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_init	t;

void	init_by_zero(void)
{
	t.c = (char)255;
	t.i = 0;
}

void	signal_handler(int signum, siginfo_t *info, void *sheet)
{
	int static	pid;

	(void)sheet;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		init_by_zero();
	}
	if (signum == SIGUSR1)
		t.c |= (0x80 >> t.i++);
	else if (signum == SIGUSR2)
		t.c ^= (0x80 >> t.i++);
	if (t.c == '\0')
		kill(info->si_pid, SIGUSR1);
	if (t.i == 8)
	{
		ft_putchar(t.c);
		init_by_zero();
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	sa.sa_sigaction = &signal_handler;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
