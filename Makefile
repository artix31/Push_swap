NAME		=	push_swap
CC		=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM		=	rm -rf
SRC		= compare error handle_sort swap_operations swap_operations2 \
			push_swaping check_input char_chk push extra_sort \

SRC_DIR		= 	srcs
SRCS		=	$(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC)))
OBJ_DIR		=	obj
OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRC:=.o))
LIBFT_PATH	=	./libft
LIBFT		=	$(LIBFT_PATH)/libft.a


all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
		$(CC) $(OBJS) $(LIBFT) $(CFLAGS) -o $(NAME)

$(OBJ_DIR):
			mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
			$(CC) $(CFLAGS) -c $< -o $@
$(LIBFT):
		make -C $(LIBFT_PATH) all
clean:
		make -C $(LIBFT_PATH) clean
				$(RM) $(OBJ_DIR)
fclean: clean
		make -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
