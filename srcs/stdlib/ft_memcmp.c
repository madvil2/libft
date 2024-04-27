/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:23:27 by kokaimov          #+#    #+#             */
/*   Updated: 2023/11/15 14:23:27 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

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
	if (n)
		return (*d1 - *d2);
	return (0);
}
