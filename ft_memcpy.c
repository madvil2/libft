/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 17:55:30 by pcollio-          #+#    #+#             */
/*   Updated: 2019/02/09 16:58:17 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dup_src;
	unsigned char	*dup_dst;

	if ((dst == NULL && src == NULL) || dst == src)
		return (NULL);
	dup_src = (unsigned char *)src;
	dup_dst = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		dup_dst[i] = dup_src[i];
		i++;
	}
	return (dup_dst);
}
