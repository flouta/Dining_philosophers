NAME=philo_bonus
CC=gcc
CFLAGS= -Wall -Wextra -Werror
SRC_B = philo_bonus_utils_4.c child_process.c philo_bonus_utils_3.c init_philos-bonus.c philo_bonus.c philo_bonus_utils.c philo_bonus_utils_2.c
OBJ_B = $(SRC_B:.c=.o)

bonus: $(NAME)
$(NAME): $(OBJ_B)
	gcc $(CFLAGS) $(OBJ_B) -o $(NAME)
clean:
	$(RM) $(OBJ_B)
fclean: clean
	$(RM) $(NAME)
re: fclean bonus


