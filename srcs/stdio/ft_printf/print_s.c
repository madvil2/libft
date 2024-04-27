/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam-vu <nam-vu@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:23:12 by nam-vu            #+#    #+#             */
/*   Updated: 2023/11/19 18:23:12 by nam-vu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_s(char *str, t_printf *args)
{
	int	res;

	if (!str)
	{
		if (args->precision < 6 && args->precision >= 0)
			args->precision = 0;
		return (print_s("(null)", args));
	}
	res = 0;
	if (args->minus)
	{
		res += ft_putnstr(str, args->precision);
		res += ft_putnchar(' ', args->width - res);
	}
	else
	{
		res += ft_putnchar(' ', args->width - ft_strlen(str) * (ft_strlen(str)
					<= (size_t)args->precision) - args->precision
				* (ft_strlen(str) > (size_t)args->precision));
		res += ft_putnstr(str, args->precision);
	}
	return (res);
}
