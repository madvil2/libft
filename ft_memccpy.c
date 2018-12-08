/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 22:39:20 by pcollio-          #+#    #+#             */
/*   Updated: 2018/12/08 18:26:45 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dup_src;
	unsigned char	*dup_dest;

	dup_src = (unsigned char *)src;
	dup_dest = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		dup_dest[i] = dup_src[i];
		if (dup_src[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
