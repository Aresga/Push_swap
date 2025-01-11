NAME = push_swap
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft/
OBJ_DIR = obj/
SRC_DIR = srcs/

SRC =	srcs/main.c \
		srcs/algorithm/algorithm.c \
		srcs/algorithm/solver_utils_ab.c \
		srcs/algorithm/solver_utils_ba.c \
		srcs/algorithm/ft_rotate_and_push.c \
		srcs/algorithm/ft_sort_big.c \
		srcs/algorithm/ft_sort_three.c \
		srcs/algorithm/ft_rotate_type.c \
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
		srcs/checker/ft_parse_args_quoted.c \
		srcs/checker/ft_check_args.c \
 		srcs/checker/ft_check_dup.c \
		srcs/checker/ft_check_sorted.c \
		srcs/checker/ft_parse.c \
		srcs/checker/ft_check_utils.c \
		srcs/list/lst_utils.c \
		srcs/list/lst_utils_2.c \
		srcs/list/ft_list_args.c \
		srcs/list/ft_add_back.c \
		srcs/list/ft_stack_new.c \
		srcs/error/ft_error_print.c \
		srcs/error/ft_free.c \
		
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