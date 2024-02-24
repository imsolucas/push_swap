
NAME = push_swap
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra -ggdb -w -fsanitize=address
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
						 $(addprefix $(SORTING_DIR)/, count_steps.c run_steps_utils.c sort_big_utils.c sort_big.c sort_decending.c sorting_utils.c sorting_utils2.c sorting.c) \

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
CYAN = \033[36m
YELLOW = \033[93m
MAGENTA = \033[35m
GREEN = \033[92m
PURPLE = \033[91m
LMAGENTA = \033[95m

# Makefile rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	@echo "$(BOLD)$(LMAGENTA)Linking objects...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(BOLD)$(LMAGENTA)$(NAME)$(RESET)$(BOLD) has been created$(RESET)"
	@echo " /\_/\ "
	@echo "( o.o )"
	@echo " > ^ <"
	@echo "$(MAGENTA)created by: $(BOLD)$(YELLOW)Lucas$(RESET)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIRS)
	@echo "$(BOLD)$(MAGENTA)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@echo "$(BOLD)$(GREEN)Compiling libft...$(RESET)"
	@make -C $(LIBFT_DIR) -s

$(PRINTF):
	@echo "$(BOLD)$(PURPLE)Compiling ft_printf...$(RESET)"
	@make -C $(PRINTF_DIR) -s

clean:
	@echo "$(BOLD)$(CYAN)Cleaning objects files...$(RESET)"
	@$(RM) $(OBJS_DIR)
	@make -C $(LIBFT_DIR) clean -s
	@make -C $(PRINTF_DIR) clean -s

fclean: clean
	@echo "$(BOLD)$(CYAN)Cleaning $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean -s
	@make -C $(PRINTF_DIR) fclean -s
	@echo "$(BOLD)$(CYAN)Cleaning $(NAME) done$(RESET)"
	@echo " /\_/\ "
	@echo "( o.o )"
	@echo " > ^ <"
	@echo "$(MAGENTA)Thanks for using$(RESET)"

re: fclean all

PHONY: all clean fclean re