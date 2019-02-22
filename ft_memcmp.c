/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 17:11:42 by pcollio-          #+#    #+#             */
/*   Updated: 2019/02/09 16:58:17 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*d1;
	unsigned char	*d2;

	d1 = (void *)s1;
	d2 = (void *)s2;
	while (n && *d1 == *d2)
	{
		d1++;
		d2++;
		n--;
	}
	if (!n)
		return (0);
	return (*d1 - *d2);
}
