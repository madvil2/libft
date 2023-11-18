/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:59:55 by kokaimov          #+#    #+#             */
/*   Updated: 2023/11/15 21:59:55 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*dup;
	unsigned int	i;

	i = 0;
	dup = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!dup)
		return (0);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}
