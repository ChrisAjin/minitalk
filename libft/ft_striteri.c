/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassa <cassassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:15:45 by cassassa          #+#    #+#             */
/*   Updated: 2024/03/22 23:15:47 by cassassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	cur;

	if (!s || !f)
		return ;
	cur = 0;
	while (s[cur])
	{
		(*f)(cur, &s[cur]);
		cur++;
	}
}
