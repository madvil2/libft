/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam-vu <nam-vu@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 23:51:54 by nam-vu            #+#    #+#             */
/*   Updated: 2023/11/20 23:51:54 by nam-vu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_get_nb_len(long nbr, char *base)
{
	int		res;
	int		radix;

	if (nbr == 0)
		return (1);
	radix = ft_strlen(base);
	res = 0;
	while (nbr > 0)
	{
		res++;
		nbr /= radix;
	}
	return (res);
}

int	pf_putnbr_base(long nbr, char *base, t_printf *args)
{
	int		radix;
	int		res;

	radix = ft_strlen(base);
	if (!radix)
		return (0);
	res = pf_get_nb_len(nbr, base);
	if (args)
	{
		if (args->precision > res)
			res = args->precision;
		if (radix == 10 && (args->plus || args->space))
			res += ft_putnchar(args->sign, 1);
		if (radix == 16 && args->hash)
		{
			res += ft_putnchar('0', 1);
			res += ft_putnchar(args->conversion, 1);
		}
		ft_putnchar('0', args->precision - pf_get_nb_len(nbr, base));
	}
	if (nbr >= radix)
		pf_putnbr_base(nbr / radix, base, NULL);
	ft_putchar_fd(base[nbr % radix], 1);
	return (res);
}

int	print_number(long nb, t_printf *args, char *base)
{
	int	res;
	int	nb_len;

	res = 0;
	if (!nb && !args->precision)
		return (ft_putnchar(' ', args->width));
	if (nb < 0)
	{
		args->sign = '-';
		args->plus = 1;
		return (print_number(-nb, args, base));
	}
	nb_len = pf_get_nb_len(nb, base);
	if (args->precision > nb_len)
		nb_len = args->precision;
	if (args->precision >= 0)
		args->filler = ' ';
	res += ft_putnchar(args->filler, (!args->minus) * (args->width
				- nb_len - (args->plus || args->space) - 2 * args->hash));
	res += pf_putnbr_base(nb, base, args);
	res += ft_putnchar(' ', (args->minus) * (args->width
				- nb_len - (args->plus || args->space) - 2 * args->hash));
	return (res);
}
