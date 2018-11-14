/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 10:06:46 by hmeys             #+#    #+#             */
/*   Updated: 2018/10/29 15:02:15 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mal;

	mal = malloc(size);
	if (!(mal = (void*)malloc(size)))
		return (NULL);
	ft_memset(mal, 0, size);
	return (mal);
}
