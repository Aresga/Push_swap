NAME = push_swap
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft/
OBJ_DIR = obj/
SRC_DIR = srcs/

SRC =	srcs/main.c \
		srcs/algorithm/cost_calculator.c \
		srcs/algorithm/rotate_operations.c \
		srcs/algorithm/ft_sort.c \
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
		srcs/checker/args_processor.c \
		srcs/checker/ft_check_args.c \
		srcs/checker/ft_check_sorted.c \
		srcs/checker/ft_parse.c \
		srcs/list/lst_utils.c \
		srcs/list/lst_position.c \
		srcs/list/ft_add_back.c \
		srcs/error/ft_error_print.c \
		srcs/error/ft_free.c \

OBJ = ${SRC:.c=.o}

INCLUDE = -L ./libft -lft

GREEN = \033[0;32m
CLEAR = \033[0m

.c.o:
	@${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	@make -C $(LIBFTDIR)
	@${CC} ${FLAGS} ${OBJ} -o ${NAME} ${INCLUDE}
	@echo "$(GREEN)✔ push_swap created$(CLEAR)"

all: ${NAME}


clean:
	@${RM} ${OBJ} 
	@echo "$(GREEN)✔ Push swap object files removed$(CLEAR)"
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	@${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean
	@echo "$(GREEN)✔ full cleanup done!$(CLEAR)"
re: clean all

.PHONY: all clean fclean re