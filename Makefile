CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = libft/ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
SRCS = 	push_swap.c \
		#ft_sa.c \
		#ft_sb.c \
		#ft_ss.c \
		#ft_pa.c \
		#ft_pb.c \
		#ft_ra.c \
		#ft_rb.c \
		#ft_rr.c \
		#ft_rra.c \
		#ft_rrb.c \
		#ft_rrr.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(FT_PRINTF)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(FT_PRINTF_DIR) fclean

re: fclean all

git:
	git add .
	git commit -m "auto update"
	git push

.PHONY: all clean fclean re