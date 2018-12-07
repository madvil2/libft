/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:31:11 by pcollio-          #+#    #+#             */
/*   Updated: 2018/12/07 23:05:32 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h> //DELETE
#include <string.h> //DELETE
#include <ctype.h> //DELETE
#include <stdio.h> //DELETE

/* ***** Part 1 - Libc functions ***** */
int			ft_atoi(const char *str);
void		ft_bzero(void *str, size_t n);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
//*ft_memccpy
//*ft_memchr
//ft_memcmp
//*ft_memcpy
//*ft_memmove
void		*ft_memset(void *str, int c, size_t n);
//ft_strcat
//*ft_strchr
//ft_strcmp
//*ft_strcpy
char		*ft_strdup(char *src)
//ft_strlcat
size_t		ft_strlen(const char *str);
//*ft_strncat
int			ft_strncmp(const char *str1, const char *str2, size_t n);
//ft_strncpy
//ft_strnstr
//*ft_strrchr
//ft_strstr
int			ft_toupper(int c);
int			ft_tolower(int c);
/* ***** Part 2 - Libc functions ***** */
//ft_memalloc
//ft_memdel
//ft_strnew
//ft_strdel
//ft_strclr
//ft_striter
//ft_striteri
//ft_strmap
//ft_strmapi
//ft_strequ
//ft_strnequ
//ft_strsub
//ft_strjoin
//ft_strtrim
//ft_strsplit
//ft_itoa
//ft_putchar
//ft_putstr
//ft_putendl
//ft_putnbr;
//ft_putchar_fd
//ft_putstr_fd
//ft_putendl_fd
//ft_putnbr_fd

/* ***** Part 3 - Bonus part ***** */
//ft_lstnew
//ft_lstdelone
//ft_lstdel
//ft_lstadd
//ft_lstiter
//ft_lstmap

#endif