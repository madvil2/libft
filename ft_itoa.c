/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:49:44 by pcollio-          #+#    #+#             */
/*   Updated: 2018/12/12 22:31:15 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*ans;
	int		len;

	len = ft_intlen(n);
	if ((ans = ft_strnew(len)) == NULL)
		return (NULL);
	if (n == 0)
		return (ft_strcpy(ft_strnew(1), "0"));
	if (n == -2147483648)
		return (ft_strcpy(ft_strnew(11), "-2147483648"));
	if (n < 0)
	{
		n *= -1;
		ans[0] = '-';
	}
	while (n)
	{
		ans[--len] = ((n % 10) + '0');
		n /= 10;
	}
	return (ans);
}
