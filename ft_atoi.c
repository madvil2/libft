/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 21:12:47 by pcollio-          #+#    #+#             */
/*   Updated: 2018/12/08 17:05:52 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	short			i;
	short			minus;
	long long int	ans;

	i = 0;
	minus = 1;
	ans = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
	str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '\e')
		return (0);
	if (str[i] == '-')
	{
		minus = -1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
		ans = ans * 10 + (str[i++] - '0');
	if (minus < 0 && ans < 0)
		return (0);
	else if (minus > 0 && ans < 0)
		return (-1);
	return ((int)ans * minus);
}
