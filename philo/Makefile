#This is the brain of the whole operation.
#Let's get this ship going!
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I.
RM = rm -rf

SRC_DIR = src
OBJ_DIR = obj

NAME = philo

SRCS = main.c print_error.c utils.c

OBJECTS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re