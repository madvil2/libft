/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam-vu <nam-vu@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:52:38 by nam-vu            #+#    #+#             */
/*   Updated: 2023/11/20 23:03:56 by nam-vu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u(unsigned int nb, t_printf *args)
{
	args->space = 0;
	args->plus = 0;
	args->hash = 0;
	return (print_number(nb, args, DEC_BASE));
}
