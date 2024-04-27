/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam-vu <nam-vu@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 01:30:58 by nam-vu            #+#    #+#             */
/*   Updated: 2023/11/25 02:20:00 by nam-vu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_printf *args, const char *format, int *offset)
{
	(*offset)++;
	while (format[*offset] == '#' || format[*offset] == '-'
		|| format[*offset] == '+' || format[*offset] == ' '
		|| format[*offset] == '0')
	{
		if (format[*offset] == '#')
			args->hash = 1;
		if (format[*offset] == '-')
			args->minus = 1;
		if (format[*offset] == '+')
			args->plus = 1;
		if (format[*offset] == ' ')
			args->space = 1;
		if (format[*offset] == '0')
			args->filler = '0';
		(*offset)++;
	}
	args->sign = 0;
	if (args->space)
		args->sign = ' ';
	if (args->plus)
		args->sign = '+';
}

void	init_args(t_printf *args, const char *format, int *offset, va_list ap)
{
	init_flags(args, format, offset);
	if (format[*offset] == '*')
		args->width = va_arg(ap, int);
	else
		args->width = ft_atoi(format + *offset);
	if (format[*offset] == '*')
		(*offset)++;
	else
		while (ft_isdigit(format[*offset]))
			(*offset)++;
	if (format[*offset] == '.')
	{
		(*offset)++;
		if (format[*offset] == '*')
			args->precision = va_arg(ap, int);
		else
			args->precision = ft_atoi(format + *offset);
	}
	if (format[*offset] == '*')
		(*offset)++;
	else
		while (ft_isdigit(format[*offset]))
			(*offset)++;
	args->conversion = format[*offset];
}

int	print_conversion(const char *s, va_list ap, t_printf *args, int *offset)
{
	init_args(args, s, offset, ap);
	if (args->width == INT32_MIN)
		return (-1);
	if (args->width < 0)
	{
		args->minus = 1;
		args->width *= -1;
	}
	(*offset)++;
	if (s[*offset - 1] == 'c')
		return (print_c(va_arg(ap, int), args));
	if (s[*offset - 1] == 's')
		return (print_s(va_arg(ap, char *), args));
	if (s[*offset - 1] == 'i' || s[*offset - 1] == 'd')
		return (print_i_d(va_arg(ap, int), args));
	if (s[*offset - 1] == 'p')
		return (print_p(va_arg(ap, uintptr_t), args));
	if (s[*offset - 1] == 'u')
		return (print_u(va_arg(ap, unsigned int), args));
	if (s[*offset - 1] == 'x' || s[*offset - 1] == 'X')
		return (print_x(va_arg(ap, unsigned int), args));
	if (s[*offset - 1] == '%')
		return (ft_putnchar('%', 1));
	ft_putchar_fd(s[*offset - 1], 1);
	return (1);
}

int	ft_printf(const char *format, ...)
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
	return (args.res);
}
