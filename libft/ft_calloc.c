/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassa <cassassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:11:08 by cassassa          #+#    #+#             */
/*   Updated: 2024/03/22 23:11:11 by cassassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*call;
	size_t	cur;

	call = malloc(count * size);
	if (!call)
		return (0);
	cur = -1;
	while (++cur < size * count)
		call[cur] = 0;
	return (call);
}
