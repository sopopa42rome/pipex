# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 18:33:40 by sopopa            #+#    #+#              #
#    Updated: 2022/11/16 12:34:03 by sopopa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT = ./libft

LIBFT_LIB = libft.a

SRCS = pipex_utils.c \
	pipex.c


OBJS	= $(SRCS:.c=.o)
RM		= rm -f
LIBC	= ar -rcs
FLAGS	= -Wall -Wextra -Werror
INCS	= ./

.c.o :
	${CC} $(FLAGS) -c $<  -o $(<:.c=.o) -I $(INCS)


$(NAME): ${OBJS}
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

all: $(NAME)
    
fclean: clean
	$(RM) $(NAME)
	make clean -C $(LIBFT)

clean:
	$(RM) $(OBJS)
	
re: fclean all

.PHONY: all clean fclean re .c.o