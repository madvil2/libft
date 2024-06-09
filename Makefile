# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kokaimov <kokaimov@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 13:31:55 by kokaimov          #+#    #+#              #
#    Updated: 2023/11/14 13:32:01 by kokaimov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=				libft.a

SRC_PATH :=			srcs/
INC_PATH :=			includes/
OBJ_PATH :=			.obj/

CFLAGS :=			-Wall -Wextra -Werror
IFLAGS :=			-I $(INC_PATH)

HFILES :=			libft\
					ft_printf\
					deque\
					hashtable\
					tree

SUB_PATH :=			ctype\
					deque\
					garbage_collector\
					list\
					stdio\
					stdio/ft_printf\
					stdlib\
					string\
					hashtable\
					tree

FILES :=			ft_isalpha\
					ft_isascii\
					ft_isalnum\
					ft_isdigit\
					ft_isprint\
					ft_isspace\
					ft_strlen\
					ft_memset\
					ft_bzero\
					ft_memcpy\
					ft_memmove\
					ft_strlcpy\
					ft_strlcat\
					ft_toupper\
					ft_tolower\
					ft_strchr\
					ft_memchr\
					ft_strrchr\
					ft_strncmp\
					ft_memcmp\
					ft_strnstr\
					ft_atoi\
					ft_calloc\
					ft_strdup\
					ft_strndup\
					ft_substr\
					ft_strjoin\
					ft_strtrim\
					ft_putchar_fd\
					ft_putstr_fd\
					ft_putendl_fd\
					ft_putnbr_fd\
					ft_split\
					ft_itoa\
					ft_strmapi\
					ft_striteri\
					ft_lstclear\
					ft_lstnew\
					ft_lstadd_back\
					ft_lstadd_front\
					ft_lstsize\
					ft_lstlast\
					ft_lstdelone\
					ft_lstiter\
					ft_lstmap\
					ft_putnbr_base\
					get_next_line\
					get_next_line_utils\
					ft_atoll\
					free_matrix\
					ft_printf\
					ft_dprintf\
					print_c\
					print_i_d\
					print_number\
					print_p\
					print_s\
					print_u\
					print_x\
					print_utils\
					deque_init\
					deque_node_init\
					deque_pop_right\
					deque_push_node_right\
					deque_sort\
					deque_iter\
					deque_pop_left\
					deque_push_node_left\
					deque_rotate\
					deque_swap\
					deque_print\
					deque_to_arr\
					ft_malloc\
					hashtable\
					hash\
					tree_add_child\
					tree_node_init\
					tree_pop_child\
					tree_add_node

HDRS :=				$(addprefix $(INC_PATH), $(addsuffix .h, $(HFILES)))
SRCS :=				$(addsuffix .c, $(FILES))
OBJS :=				$(addprefix $(OBJ_PATH), $(addsuffix .o, $(FILES)))

vpath %.c $(addprefix $(SRC_PATH),  $(SUB_PATH))

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJS): $(OBJ_PATH)%.o: %.c $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re