/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam-vu <nam-vu@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 01:27:48 by nam-vu            #+#    #+#             */
/*   Updated: 2023/11/21 01:27:48 by nam-vu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define DEC_BASE "0123456789"
# define HEXA_U_BASE "0123456789ABCDEF"
# define HEXA_L_BASE "0123456789abcdef"

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>

# include "libft.h"

typedef struct s_printf
{
	char	conversion;
	int		width;
	int		precision;
	int		minus;
	char	filler;
	int		hash;
	int		space;
	int		plus;
	int		res;
	char	sign;
	int		fd;
}	t_printf;

int		ft_dprintf(int fd, const char *format, ...);

void	init_flags(t_printf *args, const char *format, int *offset);
void	init_args(t_printf *args, const char *format, int *offset, va_list ap);
int		print_conversion(const char *s, va_list ap,
			t_printf *args, int *offset);
int		ft_printf(const char *format, ...);

int		ft_putnchar_fd(char c, int n, int fd);
int		ft_putnstr_fd(char *str, int n, int fd);

int		pf_get_nb_len(long nbr, char *base);
int		pf_putnbr_base(long nbr, char *base, t_printf *args);
int		print_number(long nb, t_printf *args, char *base);

int		print_c(char c, t_printf *args);

int		print_s(char *str, t_printf *args);

int		print_i_d(int nb, t_printf *args);

int		print_u(unsigned int nb, t_printf *args);

int		print_x(unsigned int nb, t_printf *args);

int		pf_get_addr_len(uintptr_t nbr, char *base);
int		pf_putaddr_base(uintptr_t nbr, char *base, t_printf *args);
int		print_address(uintptr_t nb, t_printf *args, char *base);
int		print_p(uintptr_t nb, t_printf *args);

#endif