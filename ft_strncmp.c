/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 21:01:42 by pcollio-          #+#    #+#             */
/*   Updated: 2018/12/07 20:26:26 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (str1[i] == str2[i])
			i++;
		else
			return (str1 - str2);
	}
	return (0);
}
