# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 18:33:40 by sopopa            #+#    #+#              #
#    Updated: 2022/11/17 19:20:33 by sopopa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT = ./libft

LIBFT_LIB = libft.a

SRCS = pipex_utils.c \
	pipex.c

CC      = gcc
OBJS	= $(SRCS:.c=.o)
RM		= rm -f
LIBC	= ar -rcs
FLAGS	= -Wall -Wextra -Werror
INCS	= ./

.c.o:
	 @${CC} $(FLAGS) -c $< -o $(<:.c=.o) -I $(INCS)


$(NAME): ${OBJS}
				@echo "\033[33mCompiling libft and pipex..."
				@make re -C $(LIBFT)/
				@cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
				@$(LIBC) $(NAME) $(OBJS)
				@$(CC) -o $(NAME) $(NAME)
				@echo "\033[32mPipex Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

all: $(NAME)
    
fclean: clean
	 @$(RM) $(NAME)
	 @make clean -C $(LIBFT)
	 @echo "\033[33mDone!"


clean:
	 @echo "\033[33mDeleting pipex..."
	 @$(RM) $(OBJS)
	
re: fclean all

.PHONY: all clean fclean re .c.o