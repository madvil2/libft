/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 22:40:19 by pcollio-          #+#    #+#             */
/*   Updated: 2018/12/11 22:59:42 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	if (s1 && s2)
	{
		if ((str = (char *)malloc(sizeof(char) * ft_strlen(s1)
		+ ft_strlen(s2) + 1)) == NULL)
			return (NULL);
		i = 0;
		while (*s1)
		{
			str[i] = *s1++;
			i++;
		}
		while (*s2)
		{
			str[i] = *s2++;
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
