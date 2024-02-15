#ifndef MINITALK_H
# define MINITALK_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>


typedef struct s_info
{
	int		index;
	unsigned char cha;
	char	str[4096];
	int flag;
	int c_pide;
}		t_info;
void			ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
#endif
