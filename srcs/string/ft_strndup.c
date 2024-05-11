/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam-vu <nam-vu@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 06:28:16 by nam-vu            #+#    #+#             */
/*   Updated: 2024/05/11 06:28:16 by nam-vu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char			*dup;
	size_t			len;

	len = ft_strlen(s);
	if (len > n)
		len = n;
	dup = ft_calloc(len + 1, sizeof(char));
	ft_strlcpy(dup, s, len + 1);
	return (dup);
}