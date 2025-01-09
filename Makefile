# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 13:48:18 by yogun             #+#    #+#              #
#    Updated: 2025/01/09 19:25:09 by agaga            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft/
OBJ_DIR = obj/
SRC_DIR = srcs/

SRC =	srcs/push_swap/push_swap.c \
		srcs/push_swap/algorithm.c \
		srcs/push_swap/ft_add_back.c \
		srcs/push_swap/ft_stack_new.c \
		srcs/push_swap/ft_check_utils.c \
		srcs/push_swap/ft_parse.c \
		srcs/push_swap/solver_utils_ab.c \
		srcs/push_swap/solver_utils_ba.c \
		srcs/push_swap/ft_rotate_and_push.c \
		srcs/operations/pa.c \
		srcs/operations/pb.c \
		srcs/operations/ra.c \
		srcs/operations/rb.c \
		srcs/operations/rr.c \
		srcs/operations/rra.c \
		srcs/operations/rrb.c \
		srcs/operations/rrr.c \
		srcs/operations/sa.c \
		srcs/operations/sb.c \
		srcs/operations/ss.c \
 		srcs/push_swap/ft_check_dup.c \
		srcs/push_swap/ft_check_sorted.c \
		srcs/push_swap/ft_error_print.c \
		srcs/push_swap/ft_free.c \
		srcs/push_swap/lst_utils.c \
		srcs/push_swap/lst_utils_2.c \
		srcs/push_swap/ft_parse_args_quoted.c \
		srcs/push_swap/ft_list_args.c \
		srcs/push_swap/ft_check_args.c \
		srcs/push_swap/ft_sort_big.c \
		srcs/push_swap/ft_sort_three.c \
		srcs/push_swap/ft_rotate_type.c \
			

OBJ = ${SRC:.c=.o}

INCLUDE = -L ./libft -lft

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${OBJ} -o ${NAME} ${INCLUDE} 

all: ${NAME}


clean:
	${RM} ${OBJ} 
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re