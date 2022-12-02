NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	   exit_write_message.c \
	   is_atoi.c create_array_atoi.c validation_args.c \
	   create_node.c create_sentinel.c connect_node.c create_stack_a.c stack_clear.c stack_len.c\
	   prepare_sort.c \
	   operation_swap.c operation_push.c operation_rotate.c operation_reverse_rotate.c \
	   execute_operation.c putstr_log.c \
	   quick_sort.c \
	   is_ascending_sorted.c is_descending_sorted.c compare_3_values.c \
	   push_swap_under_7.c sort_n_under_4.c sort_n_under_4_descending.c sort_n_under_7.c \
	   calculate_median.c calculate_section_size.c \
	   initialize_array.c initialize_sort_info_first_half.c initialize_sort_info_second_half.c \
	   is_under_b_pivot.c \
	   is_sort_stack_b_prev.c is_sort_stack_b_next.c \
	   split_first_half.c split_second_half.c push_swap_stack_b.c push_swap_stack_a.c \
	   sort_section_size_under_4.c \
	   try_swap.c \
	   try_sort.c try_sort_until_possible.c try_sort_stack_b.c try_sort_check_exist_next.c

INCLUDES_DIR = ./includes
SRCS_DIR = ./srcs
OBJS_DIR = ./objs

INCLUDE = $(addprefix -I, $(INCLUDES_DIR))
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.c=%.o))

LIBFT_DIR = ./libft
LIBFT_LIB = -lft
LIBFT_INCLUDE = $(addprefix -I, $(LIBFT_DIR)/includes)

.PHONY: libft all clean fclean bonus re test_overflow

all: libft $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(LIBFT_DIR) $(LIBFT_LIB)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $(INCLUDE) $(LIBFT_INCLUDE) $< -o $@

libft:
	make -C $(LIBFT_DIR)

bonus: all

clean:
	$(RM) -r $(OBJS_DIR)
	make clean -C $(LIBFT_DIR)

fclean:
	$(RM) -r $(OBJS_DIR)
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

norm:
	@norminette -v
	@norminette ./libft ./srcs/ ./includes

test_overflow: $(OBJS)
	$(CC) -g -fsanitize=address -o $(NAME) $^ -L$(LIBFT_DIR) $(LIBFT_LIB)

test: execute_operation

TESTS_DIR = ./tests
TEST_SRCS = execute_operation.c
TEST_OBJS = $(addprefix $(OBJS_DIR)/, $(TEST_SRCS:%.c=%.o))

execute_operation:
	$(CC) $(CFLAGS) -c $(INCLUDE) $(LIBFT_INCLUDE) $(TESTS_DIR)/$@.c -o $(OBJS_DIR)/$@.o
	$(CC) $(CFLAGS) -o $(TESTS_DIR)/$@ $(TESTS_DIR)/$@.c -L$(LIBFT_DIR) $(LIBFT_LIB) $(INCLUDE) $(LIBFT_INCLUDE)
