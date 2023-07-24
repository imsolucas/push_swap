SRC = ft_printf.c ft_printhex.c ft_putnbr.c ft_putstr.c \

NAME	= libftprintf.a

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

AR		= ar rcs

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)
	@echo cleaned objects

fclean: clean
	@rm -f $(NAME)
	@echo cleaned all

re: fclean $(NAME)

test:
	gcc *.c && ./a.out
	rm -f ./a/out
