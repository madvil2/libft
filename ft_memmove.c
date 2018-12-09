/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 21:46:41 by pcollio-          #+#    #+#             */
/*   Updated: 2018/12/10 00:09:03 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dup_src;
	unsigned char	*dup_dst;

	dup_src = (unsigned char *)src;
	dup_dst = (unsigned char *)dst;
	if (dst > src)
		while (len--)
			dup_dst[len] = dup_src[len];
	else if (src > dst)
		while (len--)
			*dup_dst++ = *dup_src++;
	return (dst);
}
