/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:11:24 by pcollio-          #+#    #+#             */
/*   Updated: 2018/12/11 17:19:28 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;

	if (size == 0)
		return (NULL);
	str = (void*)malloc(size);
	if (str)
	{
		ft_bzero(str, size);
		return (str);
	}
	return (NULL);
}
