# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 18:33:40 by sopopa            #+#    #+#              #
#    Updated: 2022/11/18 19:20:36 by sopopa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT = ./libft
PRINTF = ./ft_printf

LIBFT_LIB = libft.a
PRINTF_LIB = libftprintf.a

SRCS = pipex_utils.c \
	pipex.c

CC      = gcc
DEBUG   = -g
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
				@make re -C $(PRINTF)/
				@cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
				@$(LIBC) $(NAME) $(OBJS)
				@$(CC) -o $(NAME) $(PRINTF)/$(PRINTF_LIB) $(NAME)
				@echo "\033[32mPipex Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

all: $(NAME)

test: ${OBJS}
				@echo "\033[33mCompiling libft and pipex..."
				@make re -C $(LIBFT)/
				@cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
				@$(LIBC) $(NAME) $(OBJS)
				@$(CC) $(DEBUG) -o $(NAME) $(NAME)
				@echo "\033[32mPipex for debug compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

fclean: clean
	 @$(RM) $(NAME)
	 @make clean -C $(LIBFT)
	 @make clean -C $(PRINTF)
	 @echo "\033[33mDone!"


clean:
	 @echo "\033[33mDeleting pipex..."
	 @$(RM) $(OBJS)
	
re: fclean all

.PHONY: all clean fclean re .c.o