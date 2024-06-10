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
			res += ft_putnchar_fd(args->sign, 1, args->fd);
		if (radix == 16 && args->hash)
		{
			res += ft_putnchar_fd('0', 1, args->fd);
			res += ft_putnchar_fd(args->conversion, 1, args->fd);
		}
		ft_putnchar_fd('0', args->precision - pf_get_nb_len(nbr, base), args->fd);
	}
	if (nbr >= radix)
		pf_putnbr_base(nbr / radix, base, NULL);
	ft_putnchar_fd(base[nbr % radix], 1, args->fd);
	return (res);
}

int	print_number(long nb, t_printf *args, char *base)
{
	int	res;
	int	nb_len;

	res = 0;
	if (!nb && !args->precision)
		return (ft_putnchar_fd(' ', args->width, args->fd));
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
	res += ft_putnchar_fd(args->filler, (!args->minus) * (args->width
				- nb_len - (args->plus || args->space) - 2 * args->hash), args->fd);
	res += pf_putnbr_base(nb, base, args);
	res += ft_putnchar_fd(' ', (args->minus) * (args->width
				- nb_len - (args->plus || args->space) - 2 * args->hash), args->fd);
	return (res);
}
