/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam-vu <nam-vu@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:36:17 by nam-vu            #+#    #+#             */
/*   Updated: 2023/11/19 17:36:17 by nam-vu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(char c, t_printf *args)
{
	int	res;

	res = 0;
	if (args->width > 1)
	{
		if (args->minus == 1)
		{
			res += ft_putnchar(c, 1);
			res += ft_putnchar(' ', args->width - 1);
		}
		else
		{
			res += ft_putnchar(' ', args->width - 1);
			res += ft_putnchar(c, 1);
		}
	}
	else
		res += ft_putnchar(c, 1);
	return (res);
}
