NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = 	parsing.c \
		utils_1.c \
		utils_2.c

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