# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/04 21:35:29 by pcollio-          #+#    #+#              #
#    Updated: 2018/12/07 19:36:06 by pcollio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_*.c

OUT = ft_*.o

INCLUDES = libft.h

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRCS) -I $(INCLUDES)
	ar rc $(NAME) $(OUT)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re