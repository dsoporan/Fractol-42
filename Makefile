# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsoporan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/31 14:47:26 by dsoporan          #+#    #+#              #
#    Updated: 2017/05/31 15:40:24 by dsoporan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

FLAGS =	-Wall -Wextra -Werror

SRCS =	*.c

OBJS =		$(SRCS:.c=.o)

all :		$(NAME)

$(NAME) :
			@make -C libft/ fclean
			@make -C libft/ 
			@$(CC) $(FLAGS) -c $(SRCS)
			@$(CC) $(FLAGS) -o $(NAME) $(OBJS) libft/libft.a -lmlx -framework OpenGL -framework AppKit

clean :
			@-rm -f $(OBJS)
			@make -C libft/ clean

fclean :	clean	
			 @make -C libft/ fclean
			@-rm -f $(NAME)

re :		fclean all
