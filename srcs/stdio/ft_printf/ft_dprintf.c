/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam-vu <nam-vu@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:38:20 by nam-vu            #+#    #+#             */
/*   Updated: 2024/06/09 22:38:20 by nam-vu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dprintf(int fd, const char *format, ...)
{
	int			offset;
	va_list		ap;
	t_printf	args;
	int			stdout;

	if (!format)
		return (-1);
	va_start(ap, format);
	offset = 0;
	args.res = 0;
	stdout = dup(STDOUT_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	while (format[offset])
	{
		args.hash = 0;
		args.minus = 0;
		args.plus = 0;
		args.space = 0;
		args.filler = ' ';
		args.precision = -1;
		args.width = -1;
		if (format[offset] == '%')
			args.res += print_conversion(format, ap, &args, &offset);
		else
			args.res += ft_putnchar(format[offset++], 1);
	}
	va_end(ap);
	dup2(stdout, STDOUT_FILENO);
	return (args.res);
}