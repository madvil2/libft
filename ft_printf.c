/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:18:11 by kokaimov          #+#    #+#             */
/*   Updated: 2024/02/11 16:58:40 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_string(va_arg(ap, char *));
	else if (specifier == 'p')
		count += print_pointer(va_arg(ap, uintptr_t), 1);
	else if (specifier == 'd')
		count += ft_putnbr_base((long)va_arg(ap, int), DEC);
	else if (specifier == 'i')
		count += ft_putnbr_base((long)va_arg(ap, int), DEC);
	else if (specifier == 'u')
		count += ft_putnbr_base((long)va_arg(ap, unsigned int), DEC);
	else if (specifier == 'x')
		count += ft_putnbr_base((long)va_arg(ap, unsigned int), HEX);
	else if (specifier == 'X')
		count += ft_putnbr_base((long)va_arg(ap, unsigned int), HEX_U);
	else if (specifier == '%')
		count += print_char('%');
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}
