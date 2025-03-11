# This is the brain of the whole operation.
# Let's get this ship going!
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
RM = rm -rf

BONUS_SRC_DIR = bonus_src
BONUS_OBJ_DIR = bonus_obj

NAME = philo_bonus

BSRCS = bonus.c

OBJECTS = $(addprefix $(BONUS_OBJ_DIR)/, $(BSRCS:.c=.o))

all: bonus

bonus: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS)

$(BONUS_OBJ_DIR)/%.o: $(BONUS_SRC_DIR)/%.c
	@mkdir -p $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(BONUS_OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus