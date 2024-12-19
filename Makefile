CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = 	push_swap.c \
		ft_sa.c \
		ft_sb.c \
		ft_ss.c \
		ft_pa.c \
		ft_pb.c \
		ft_ra.c \
		ft_rb.c \
		ft_rr.c \
		ft_rra.c \
		ft_rrb.c \
		ft_rrr.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re