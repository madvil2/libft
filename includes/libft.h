/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:26:59 by kokaimov          #+#    #+#             */
/*   Updated: 2023/11/14 18:30:25 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <limits.h>

# include "deque.h"
# include "ft_printf.h"

# define BUFFER_SIZE 10
# define PERM 1
# define TEMP 0

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isalnum(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
size_t			ft_strlen(const char *s);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
void			*ft_memchr(const void *s, int c, size_t n);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_atoi(const char *nptr);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_lstclear(t_list **lst, void (*del)(void *));
t_list			*ft_lstnew(void *content);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

// additional
int				ft_putnbr_base(long nbr, char *base);
long long int	ft_atoll(const char *nptr);
void			free_matrix(char **arr);

// get_next_line
char			*get_next_line(int fd);
int				line_len(t_list *list);
void			free_list(t_list **list, t_list *clear_node, char *buf);
void			clear_list(t_list **list);
void			str_copy(t_list *list, char *str);

// ft_printf.c
int				ft_printf(const char *format, ...);

// ft_printf_utils.c
int				print_char(char c);
int				print_string(char *str);
int				print_pointer(uintptr_t nbr, int flag);

//garbage_collector.c
void			gc_free(int flag);
void			ft_malloc(size_t size, int flag);

#endif