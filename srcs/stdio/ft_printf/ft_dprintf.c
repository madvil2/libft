/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam-vu <nam-vu@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:14:20 by nam-vu            #+#    #+#             */
/*   Updated: 2024/06/10 21:14:20 by nam-vu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	restore_flags(t_printf *args, int fd)
{
	args->fd = fd;
	args->hash = 0;
	args->minus = 0;
	args->plus = 0;
	args->space = 0;
	args->filler = ' ';
	args->precision = -1;
	args->width = -1;
}

int	ft_dprintf(int fd, const char *format, ...)
{
	int			offset;
	va_list		ap;
	t_printf	args;

	if (!format)
		return (-1);
	va_start(ap, format);
	offset = 0;
	args.res = 0;
	while (format[offset])
	{
		restore_flags(&args, fd);
		if (format[offset] == '%')
			args.res += print_conversion(format, ap, &args, &offset);
		else
			args.res += ft_putnchar_fd(format[offset++], 1, args.fd);
	}
	va_end(ap);
	return (args.res);
}
