/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassa <cassassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:43:19 by cassassa          #+#    #+#             */
/*   Updated: 2024/03/12 17:50:18 by cassassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define PID_MAX 4194304

typedef struct info
{
	int		i;
	char	c;
}			t_init;

void		ft_putnbr(int nb);
int			ft_atoi(const char *str);
void		ft_putstr(char *s);
void		ft_putchar(char c);
#endif
