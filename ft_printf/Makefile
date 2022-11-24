# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 21:23:18 by sopopa            #+#    #+#              #
#    Updated: 2022/11/24 16:22:07 by sopopa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = ../libft

LIBFT_LIB = libft.a

SRCS = ft_printf.c \
		ft_printf_unsigned_int.c \
		ft_printf_pointaddress.c \
		ft_printf_unsigned_int.c \
		ft_printf_utils.c \
		ft_printf_number.c \
		ft_printf_hexadecimal.c \

OBJS	= $(SRCS:.c=.o)
RM		= rm -f
LIBC	= ar -rcs
FLAGS	= -Wall -Wextra -Werror
INCS	= ./

.c.o :
	 @${CC} $(FLAGS) -c $< -o $(<:.c=.o) -I $(INCS)


$(NAME): ${OBJS}
	 @make re -C $(LIBFT)/
	 @cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	 @$(LIBC) $(NAME) $(OBJS)

all: $(NAME)
    
fclean: clean
	 @$(RM) $(NAME)
	 @make clean -C $(LIBFT)

clean:
	 @$(RM) $(OBJS)
	
re: fclean all

.PHONY: all clean fclean re .c.o
