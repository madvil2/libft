/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 02:07:21 by kokaimov          #+#    #+#             */
/*   Updated: 2024/04/27 02:12:09 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnchar_fd(char c, int n, int fd)
{
	int	i;

	i = 0;
	if (n <= 0)
		return (0);
	while (i++ < n)
		ft_putchar_fd(c, fd);
	return (n);
}

int	ft_putnstr_fd(char *str, int n, int fd)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		while (str[i])
			ft_putchar_fd(str[i++], fd);
		return (i);
	}
	while (str[i] && i < n)
		ft_putchar_fd(str[i++], fd);
	return (i);
}
