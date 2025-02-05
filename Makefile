NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = 	parsing.c \
		./utils/utils_1.c \
		./utils/utils_2.c \
		./utils/utils_3.c \
		./utils/utils_4.c \
		./inst/inst_1.c \
		./inst/inst_2.c \
		./inst/inst_3.c \
		./algo/algo.c \
		./algo/algo_2.c \
		main.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

git:
	git status
	git add .
	git commit -m "auto update"
	git push

.PHONY: all clean fclean re