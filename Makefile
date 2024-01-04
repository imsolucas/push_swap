
NAME = push_swap
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra -ggdb -fsanitize=address

SRCS_MAIN = src/checks.c src/push_swap.c src/lst_utils.c
OBJS = $(SRCS_MAIN:.c=.o)

LIBFT_MAKE = make all -C libft
LIBFT_CP = cp libft/libft.a .

PRINTF_MAKE = make all -C ft_printf
PRINTF_CP = cp ft_printf/libftprintf.a .

all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	${RM} $(BONUS_OBJS)
	$(LIBFT_MAKE)
	$(LIBFT_CP)
	${PRINTF_MAKE}
	${PRINTF_CP}
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft.a libftprintf.a

clean:
	$(RM) $(OBJS) $(BONUS_OBJS) libft.a libftprintf.a
	make fclean -C libft
	make fclean -C ft_printf

fclean:
	$(RM) $(NAME)
	make fclean -C libft
	make fclean -C ft_printf
	$(RM) libft.a libftprintf.a
	make clean

re: fclean all

PHONY: all clean fclean re