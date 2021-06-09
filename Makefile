# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/25 15:24:05 by soooh             #+#    #+#              #
#    Updated: 2021/06/10 03:05:05 by soooh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

CC				= gcc
RM				= rm -rf
SRCS			= ./srcs/push_swap.c\
					./srcs/ps_utils.c\
					./srcs/ps_init.c\
					./srcs/ps_linked.c\
					./srcs/ps_push_pop.c\
					./srcs/ps_double.c\
					./srcs/ps_sort.c\
					./srcs/ps_under_five.c\
					./srcs/ps_atob.c\
					./srcs/ps_btoa.c\
					./srcs/ps_prev_stack.c

CFLAGS			= -Wall -Wextra -Werror
SFLAGS    = -fsanitize=address

INC_LINK 		= -I./libft -I./srcs

LIBFT 			= libft.a
LIBFT_LIB 		= ./libft

OBJS			= $(SRCS:.c=.o)

all: $(NAME)

$(NAME):		$(OBJS) libft
	@cp $(LIBFT_LIB)/$(LIBFT) $(LIBFT)
	@$(CC) -o $(NAME) $(CFLAGS) $(SFLAGS) $(INC_LINK) $(OBJS) $(LIBFT)
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