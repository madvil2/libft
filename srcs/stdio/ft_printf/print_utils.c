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

int	ft_putnchar(char c, int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		return (0);
	while (i++ < n)
		ft_putchar_fd(c, 1);
	return (n);
}

int	ft_putnstr(char *str, int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		while (str[i])
			ft_putchar_fd(str[i++], 1);
		return (i);
	}
	while (str[i] && i < n)
		ft_putchar_fd(str[i++], 1);
	return (i);
}
