/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassa <cassassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:10:25 by cassassa          #+#    #+#             */
/*   Updated: 2024/03/22 23:10:27 by cassassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

typedef struct s_opt
{
	int	sharp;
	int	space;
	int	plus;
	int	min_width;
	int	minus;
	int	dot;
	int	precision;
	int	offset;
	int	zero;
	int	zero_offset;
}		t_opt;

int		ft_printf(const char *str, ...);

int		pf_printchar(char c, t_opt opt);
int		pf_printstr(char *str, t_opt opt);
int		pf_printpointer(void *ptr, t_opt opt);
int		pf_printnum(long nl, t_opt opt);
int		pf_printunum(unsigned long nl, t_opt opt);
int		pf_printbnum(int nl, int is_maj, t_opt opt);

int		pf_strlen(char *str);
int		pf_atoi(const char *str, int *o_cur);
int		print_str(char *str);
int		print_char(char c);
int		in_set(char c, char *set);
int		print_number(long nl);
void	init_opt(t_opt *opt);
#endif
