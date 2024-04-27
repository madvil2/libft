/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:12:49 by kokaimov          #+#    #+#             */
/*   Updated: 2023/11/14 19:12:49 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned long int	i;

	if ((dest == NULL && src == NULL) || dest == src)
		return (NULL);
	i = n;
	if (src > dest)
		while (i--)
			*((unsigned char *)dest + (n - i - 1))
				= *((unsigned char *)src + (n - i - 1));
	else if (dest > src)
		while (i--)
			*((unsigned char *)dest + i) = *((unsigned char *)src + i);
	return (dest);
}
