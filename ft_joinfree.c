/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 22:07:23 by pcollio-          #+#    #+#             */
/*   Updated: 2019/02/09 16:58:18 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joinfree(char **s1, char **s2)
{
	char	*str;
	int		i;
	int		j;

	if (!(*s1) && !(*s2))
		return (NULL);
	if (!(*s2))
		return ((char *)*s1);
	if ((str = ft_memalloc(ft_strlen(*s1) + ft_strlen(*s2) + 1)) == NULL)
		return (NULL);
	i = 0;
	while ((*s1)[i])
	{
		str[i] = (*s1)[i];
		i++;
	}
	j = 0;
	while ((*s2)[j])
		str[i++] = (*s2)[j++];
	str[i] = '\0';
	free((void *)*s2);
	free((void *)*s1);
	return (str);
}
