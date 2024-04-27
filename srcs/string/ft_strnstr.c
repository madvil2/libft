/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:39:04 by kokaimov          #+#    #+#             */
/*   Updated: 2023/11/16 16:50:59 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (*little == '\0')
		return ((char *)big);
	if (!big && len == 0)
		return (NULL);
	while (*big && (len-- >= ft_strlen(little)))
	{
		if (ft_strncmp(big, little, ft_strlen(little)) != 0)
			big++;
		else
			return ((char *)big);
	}
	return (0);
}
