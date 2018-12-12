/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 19:00:01 by pcollio-          #+#    #+#             */
/*   Updated: 2018/12/12 21:49:07 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *d;

	d = (unsigned char *)s;
	while (n--)
	{
		if (*d == (unsigned char)c)
			return (d);
		d++;
	}
	return (NULL);
}
