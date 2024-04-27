/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam-vu <nam-vu@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 23:52:37 by nam-vu            #+#    #+#             */
/*   Updated: 2023/11/21 00:07:40 by nam-vu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_i_d(int nb, t_printf *args)
{
	args->hash = 0;
	if (args->precision < 0 && args->filler == '0'
		&& (nb < 0 || args->plus || args->space))
	{
		args->precision = args->width - 1 + (args->width == 1);
		args->width = 0;
	}
	if (!args->precision && !nb && (args->space || args->plus))
		return (print_c(args->sign, args));
	return (print_number(nb, args, DEC_BASE));
}
