NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

ARFLAGS = rcs

SRCS = get_next_line.c get_next_line_utils.c

LIBFT_DIR = ../..
INCLUDES_DIR = ../../includes
OBJS_DIR = ../../objs

INCLUDE = $(addprefix -I, $(INCLUDES_DIR))

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.c=%.o))

.PHONY: all re

all:	$(NAME)

$(NAME):	$(OBJS)
		$(AR) $(ARFLAGS) $(LIBFT_DIR)/$(NAME) $(OBJS)
		
$(OBJS_DIR)/%.o:	%.c
		$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

re:	all
