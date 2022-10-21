NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	   exit_write_message.c \
	   is_atoi.c validation_args.c \
	   create_node.c create_stack_a.c stack_clear.c \
	   create_log_node.c add_back_list_log_node.c log_list_clear.c \
	   putstr_log.c
	   
# search_sentinel.c 
INCLUDES_DIR = ./includes
SRCS_DIR = ./srcs
OBJS_DIR = ./objs

INCLUDE = $(addprefix -I, $(INCLUDES_DIR))
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.c=%.o))

LIBFT_NAME = libft.a
LIBFT_DIR = ./libft
LIBFT_LIB = -lft
LIBFT_INCLUDE = $(addprefix -I, $(LIBFT_DIR)/includes)

.PHONY: all clean fclean bonus re

all: $(OBJS_DIR) $(LIBFT_NAME) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) $(LIBFT_LIB)

$(OBJS_DIR):
	mkdir -p $@

$(LIBFT_NAME): $(LIBFT_DIR)
	make -C $^

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $(INCLUDE) $(LIBFT_INCLUDE) $< -o $@

clean: $(OBJS_DIR)
	$(RM) -r $^
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

bonus: all

re: fclean all

