/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam-vu <nam-vu@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 01:17:23 by nam-vu            #+#    #+#             */
/*   Updated: 2023/11/21 01:17:23 by nam-vu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_x(unsigned int nb, t_printf *args)
{
	args->space = 0;
	args->plus = 0;
	if (nb == 0 && args->precision == 0)
		return (ft_putnchar(' ', args->width));
	if (nb != 0 && args->precision < 0 && args->filler == '0' && args->hash)
		args->precision = args->width - 2;
	if (nb == 0)
		args->hash = 0;
	if (args->conversion == 'x')
		return (print_number(nb, args, HEXA_L_BASE));
	return (print_number(nb, args, HEXA_U_BASE));
}
