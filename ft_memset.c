/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:33:44 by pcollio-          #+#    #+#             */
/*   Updated: 2018/12/07 22:50:46 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned long int	i;
	unsigned char		*ptr;

	ptr = (unsigned char*)str;
	i = 0;
	while (i < n)
		ptr[i++] = (unsigned char)c;
	return (ptr);
}
