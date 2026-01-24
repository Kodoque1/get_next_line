NAME := get_next_line.a
LIBFT_PATH ?= ../libft
SRC := get_next_line.c get_next_line_utils.c
OBJ  := $(SRC:.c=.o)
MAKEFLAGS += -r
RM := rm -f
CC := cc
AR = ar rcs
CFLAGS := -Werror -Wextra -Wall
CFLAGS += -Iincludes -I$(LIBFT_PATH)/includes

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

# === CLEANING UP ===
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all
