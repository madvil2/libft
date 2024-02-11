/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:36:06 by kokaimov          #+#    #+#             */
/*   Updated: 2023/11/19 21:23:29 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_char(char c)
{
	return (write(1, &c, 1));
}

int	print_string(char *str)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
		print_char(str[i++]);
	return (i);
}

int	print_pointer(uintptr_t nbr, int flag)
{
	unsigned int	base_len;
	unsigned int	count;
	char			*base;

	base = "0123456789abcdef";
	base_len = 16;
	count = 0;
	if (!nbr && flag)
		return (write(1, "(nil)", 5));
	if (flag)
		count += write(1, "0x", 2);
	if (nbr >= base_len)
		count += print_pointer(nbr / base_len, 0);
	write(1, &base[nbr % base_len], 1);
	return (count + 1);
}
