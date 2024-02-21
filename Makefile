
NAME = push_swap
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra -ggdb -w #-fsanitize=address
INCLUDES = -Iincludes -Ilib/libft -Ilib/ft_printf

# Source files
SRCS_DIR = srcs
OPERATION_DIR = operation
MAIN_DIR = main
CHECK_DIR = check
LINKEDLIST_DIR = linkedlist
SORTING_DIR = sorting
SRCS_FILES = $(addprefix $(MAIN_DIR)/, main.c) \
						 $(addprefix $(CHECK_DIR)/, checks.c check_numbers.c) \
						 $(addprefix $(LINKEDLIST_DIR)/, lst_create.c lst_count_num.c) \
						 $(addprefix $(OPERATION_DIR)/, operation_utils.c operation.c push.c reverse_rotate.c rotate.c swap.c) \
						 $(addprefix $(SORTING_DIR)/, count_steps.c run_steps_utils.c sort_big.c sorting_utils.c sorting_utils2.c sorting.c) \

SRCS = $(addprefix $(SRCS_DIR)/,$(SRCS_FILES))

# Object files
OBJS_DIR = objs
OBJS_DIRS = $(OBJS_DIR) $(OBJS_DIR)/$(MAIN_DIR) $(OBJS_DIR)/$(OPERATION_DIR) $(OBJS_DIR)/$(CHECK_DIR) $(OBJS_DIR)/$(LINKEDLIST_DIR) $(OBJS_DIR)/$(SORTING_DIR)
OBJS_FILES = $(patsubst %.c,%.o,$(SRCS_FILES))
OBJS = $(addprefix $(OBJS_DIR)/,$(OBJS_FILES))

# Librairies
LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = lib/ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

LIBS = -L$(LIBFT_DIR) -L$(PRINTF_DIR) -lft -lftprintf

# Colors and text formatting
RESET = \033[0m
BOLD = \033[1m
DIM = \033[2m
UNDERLINE = \033[4m
BLINK = \033[5m
INVERT = \033[7m
LIGHT_BLUE = \033[94m
YELLOW = \033[93m

# Makefile rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	@echo "$(BOLD)$(LIGHT_BLUE)Linking objects...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(BOLD)$(LIGHT_BLUE)$(NAME)$(RESET)$(BOLD) has been created$(RESET)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIRS)
	@echo "$(BOLD)$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@echo "$(BOLD)$(YELLOW)Compiling libft...$(RESET)"
	@make -C $(LIBFT_DIR) -s

$(PRINTF):
	@echo "$(BOLD)$(YELLOW)Compiling ft_printf...$(RESET)"
	@make -C $(PRINTF_DIR) -s

clean:
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning objects files...$(RESET)"
	@$(RM) $(OBJS_DIR)
	@make -C $(LIBFT_DIR) clean -s
	@make -C $(PRINTF_DIR) clean -s

fclean: clean
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean -s
	@make -C $(PRINTF_DIR) fclean -s

re: fclean all

PHONY: all clean fclean re