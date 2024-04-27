/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:01:50 by kokaimov          #+#    #+#             */
/*   Updated: 2023/11/14 22:01:50 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (*(s1 + i) && *(s1 + i) == *(s2 + i) && i < n - 1)
		i++;
	if (n)
		return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
	return (0);
}
