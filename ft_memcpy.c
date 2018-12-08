/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 17:55:30 by pcollio-          #+#    #+#             */
/*   Updated: 2018/12/08 18:30:32 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
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
		i++;
	}
	return (dup_dest);
}
