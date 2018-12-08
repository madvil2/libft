/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:31:11 by pcollio-          #+#    #+#             */
/*   Updated: 2018/12/08 23:08:37 by pcollio-         ###   ########.fr       */
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
void		*ft_memccpy(void *dest, const void *src, int c, size_t n);
//*ft_memchr
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
//*ft_memmove
void		*ft_memset(void *str, int c, size_t n);
char		*ft_strcat(char *dest, const char *src);
//*ft_strchr
int			ft_strcmp(const char *str1, const char *str2);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strdup(char *src);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
size_t		ft_strlen(const char *str);
char		*ft_strncat(char *dest, char *src, size_t n);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
char		*ft_strncpy(char *dest, const char *src, size_t n);
//ft_strnstr
//*ft_strrchr
char		*ft_strstr(const char *s1, const char *s2);
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