/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 22:12:07 by pcollio-          #+#    #+#             */
/*   Updated: 2018/12/11 22:39:18 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	i;

	if ((d = (char *)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	if (s)
	{
		i = 0;
		while (i < len)
		{
			d[i] = s[start];
			start++;
			i++;
		}
		d[i] = '\0';
		return (d);
	}
	return (NULL);
}
