#This is the brain of the whole operation.
#Let's get this ship going!

# ──────────────────────────────────────────────────────────────────────────────
# COLOURS
# ──────────────────────────────────────────────────────────────────────────────

BLACK        = \\033[0;30m
RED          = \\033[0;31m
GREEN        = \\033[0;32m
YELLOW       = \\033[0;33m
BLUE         = \\033[0;34m
MAGENTA      = \\033[0;35m
CYAN         = \\033[0;36m
WHITE        = \\033[0;37m

BOLD_BLACK   = \\033[1;30m
BOLD_RED     = \\033[1;31m
BOLD_GREEN   = \\033[1;32m
BOLD_YELLOW  = \\033[1;33m
BOLD_BLUE    = \\033[1;34m
BOLD_MAGENTA = \\033[1;35m
BOLD_CYAN    = \\033[1;36m
BOLD_WHITE   = \\033[1;37m

RESET        = \\033[0m

# ──────────────────────────────────────────────────────────────────────────────
# COMPILER SETTINGS
# ──────────────────────────────────────────────────────────────────────────────

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -I.
RM = rm -rf

# ──────────────────────────────────────────────────────────────────────────────
# DIRECTORIES
# ──────────────────────────────────────────────────────────────────────────────

SRC_DIR = src
OBJ_DIR = obj

# ──────────────────────────────────────────────────────────────────────────────
# FILES
# ──────────────────────────────────────────────────────────────────────────────

NAME = philo

SRCS = main.c		cleanup.c	philo_actions.c \
       printing.c	utils.c		setting_table.c

OBJECTS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# ──────────────────────────────────────────────────────────────────────────────
# TARGETS
# ──────────────────────────────────────────────────────────────────────────────

.PHONY : all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) -o $(NAME) $(OBJECTS)
	@echo "$(GREEN)Executable ready!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE)Compiling $<!$(RESET)"

clean :
	@echo "$(RED)Cleaning object files…$(RESET)"
	@$(RM) $(OBJ_DIR)

fclean : clean
	@echo "$(RED)Cleaning executable…$(RESET)"
	@$(RM) $(NAME)

re : fclean all