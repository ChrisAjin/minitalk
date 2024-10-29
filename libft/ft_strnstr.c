/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassa <cassassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:16:27 by cassassa          #+#    #+#             */
/*   Updated: 2024/03/22 23:16:29 by cassassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	cur1;
	size_t	cur2;
	size_t	needle_len;

	if (!needle[0])
		return ((char *)haystack);
	cur1 = 0;
	needle_len = ft_strlen(needle);
	while (haystack[cur1] && (cur1 + needle_len - 1) < len)
	{
		cur2 = 0;
		while (needle[cur2] && haystack[cur1 + cur2] == needle[cur2])
		{
			if (cur2 == needle_len - 1)
				return ((char *)(haystack + cur1));
			cur2++;
		}
		cur1++;
	}
	return (0);
}
