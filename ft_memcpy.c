/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:02:25 by kokaimov          #+#    #+#             */
/*   Updated: 2023/11/14 19:02:49 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned long int	i;

	if ((dest == NULL && src == NULL) || dest == src)
		return (NULL);
	i = n;
	while (i--)
		*((unsigned char *)dest++) = *((unsigned char *)src++);
	return (dest - n);
}
