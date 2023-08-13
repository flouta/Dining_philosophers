NAME=philo
CC=gcc
CFLAGS= -Wall -Wextra -Werror
RM= rm -f
SRC =  philo_utils_4.c philo_utils_3.c philo_utils_2.c parsing.c philo_utils.c philo.c init_philos.c
OBJ = $(SRC:.c=.o)

all: $(NAME)



$(NAME): $(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(NAME)
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all


