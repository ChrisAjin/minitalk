/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassa <cassassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:09:18 by cassassa          #+#    #+#             */
/*   Updated: 2024/03/22 23:09:20 by cassassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include "../libft.h"
# define GNL_CLEAR 1
# define GNL_KEEP 0

typedef struct s_prev_list
{
	char				*prev;
	int					fd;
	struct s_prev_list	*next;
}	t_prev_list;

long	charchr(const char *s, char c);
char	*gnl_strjoin(char *s1, char const *s2);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
void	shiftstr(char **str, size_t start);
#endif