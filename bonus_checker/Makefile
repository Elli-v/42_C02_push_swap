# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/17 02:30:41 by soooh             #+#    #+#              #
#    Updated: 2021/06/18 02:37:14 by soooh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= checker

CC				= gcc
RM				= rm -rf
INC_LINK 		= -I./srcs -I./srcs/gnl
SRCS			= ./srcs/checker.c\
					./srcs/checker_op.c\
					./srcs/ck_free.c\
					./srcs/ck_init.c\
					./srcs/ck_linked.c\
					./srcs/ck_prev_stack.c\
					./srcs/ck_utils.c\
					./srcs/ck_double.c\
					./srcs/ck_push_pop.c\
					./srcs/gnl/get_next_line.c\
					./srcs/gnl/get_next_line_utils.c


CFLAGS			= -Wall -Wextra -Werror
# CFLAGS 		= -g3 -fsanitize=address

LIBFT 			= libft.a
LIBFT_LIB 		= ../libft

OBJS			= $(SRCS:.c=.o)

all: $(NAME)

$(NAME):		$(OBJS) libft
	@cp $(LIBFT_LIB)/$(LIBFT) $(LIBFT)
	@$(CC) -o $(NAME) $(CFLAGS) $(INC_LINK) $(OBJS) $(LIBFT)
	@$(RM) $(LIBFT)
	
#libft compile
libft:
	@$(MAKE) -C $(LIBFT_LIB) all

clean:
	@$(MAKE) -C $(LIBFT_LIB) clean
	@$(RM) $(OBJS)

fclean:			clean
	@$(MAKE) -C $(LIBFT_LIB) fclean
	@$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re libft