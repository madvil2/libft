/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam-vu <nam-vu@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 00:44:54 by nam-vu            #+#    #+#             */
/*   Updated: 2023/11/21 00:44:54 by nam-vu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_get_addr_len(uintptr_t nbr, char *base)
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

int	pf_putaddr_base(uintptr_t nbr, char *base, t_printf *args)
{
	unsigned int		radix;
	int					res;

	radix = ft_strlen(base);
	if (!radix)
		return (0);
	res = pf_get_addr_len(nbr, base);
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
		ft_putnchar('0', args->precision - pf_get_addr_len(nbr, base));
	}
	if (nbr >= radix)
		pf_putaddr_base(nbr / radix, base, NULL);
	ft_putchar_fd(base[nbr % radix], 1);
	return (res);
}

int	print_address(uintptr_t nb, t_printf *args, char *base)
{
	int				res;
	uintptr_t		nb_len;

	res = 0;
	if (!nb && !args->precision)
		return (ft_putnchar(' ', args->width));
	nb_len = pf_get_addr_len(nb, base)
		+ 2 * (ft_strlen(base) == 16 && args->hash);
	res += ft_putnchar(args->filler, (!args->minus) * (args->width
				- nb_len - (args->plus || args->space)));
	res += pf_putaddr_base(nb, base, args);
	res += ft_putnchar(' ', (args->minus) * (args->width
				- nb_len - (args->plus || args->space)));
	return (res);
}

int	print_p(uintptr_t nb, t_printf *args)
{
	if (!nb)
	{
		args->precision = -1;
		return (print_s("(nil)", args));
	}
	args->hash = 1;
	args->precision = -1;
	args->conversion = 'x';
	args->filler = ' ';
	return (print_address(nb, args, HEXA_L_BASE));
}
