NAME = push_swap

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBFTDIR = libft/

OBJ_DIR = obj/

SRC_DIR = srcs/

SRC =	srcs/main.c \
		srcs/algorithm/ft_rotation_operations.c \
		srcs/algorithm/ft_sort.c \
		srcs/algorithm/ft_sort_three.c \
		srcs/algorithm/ft_rotation_optimizer.c \
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
		srcs/checker/ft_init_stack.c \
		srcs/checker/ft_check_args.c \
		srcs/checker/ft_atol.c \
		srcs/list/ft_lst_utils.c \
		srcs/list/ft_lst_position.c \
		srcs/list/ft_math.c \
		srcs/error/ft_error.c \
		srcs/error/ft_free.c \

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

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
	@${RM} -rf ${OBJ_DIR} 
	@echo "$(GREEN)✔ Push swap object files removed$(CLEAR)"
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	@${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean
	@echo "$(GREEN)✔ full cleanup done!$(CLEAR)"
re: clean all

.PHONY: all clean fclean re