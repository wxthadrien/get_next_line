/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 15:06:10 by hmeys             #+#    #+#             */
/*   Updated: 2018/10/29 14:40:29 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;
	int		y;

	y = 0;
	i = start;
	if (!(new = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (!s)
		return (NULL);
	if (s != NULL)
	{
		while (y < (int)len)
		{
			new[y] = s[i];
			y++;
			i++;
		}
		new[y] = '\0';
	}
	return (new);
}
