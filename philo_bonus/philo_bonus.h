/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 21:01:50 by flouta            #+#    #+#             */
/*   Updated: 2022/07/02 21:01:52 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <signal.h>
# include <stdatomic.h>

typedef struct s_philo
{
	int						number;
	_Atomic unsigned int	number_of_meals;
	_Atomic unsigned long	last_meal;
	unsigned long			start_time;
	unsigned long			prog_start_time;
	struct s_philo			*next;	
}	t_philo;

typedef struct s_death
{
	unsigned int	*inputs;
	t_philo			*philo;
	sem_t			*print;
	int				ac;
}	t_death;

typedef struct s_semaphores
{
	sem_t	*print;
	sem_t	*forks;
}	t_sema;

typedef struct s_exit_val
{
	int				status;
	int				statuscode;
}	t_exit_val;
unsigned int	ft_atoi(const char *str);
unsigned int	*parse_input(int ac, char **av);
void			ft_usleep_sem(unsigned int duration);
void			take_forks_sem(t_death *infos, unsigned long s_t, sem_t *f);
void			eating_sem(t_death *infos, unsigned int start_time);
void			release_forks_sem(sem_t *forks);
void			sleeping_sem(t_death *infos, unsigned int s_t);
void			thinking_sem(t_philo *philo, unsigned int s_t, sem_t *print);
unsigned int	curr_time_sem(void);
void			ft_printf_sem(t_philo *p, unsigned long s_t, int i, sem_t *pr);
t_philo			*init_philos_sem(t_philo *head, unsigned int *inputs);
int				check_death_sem(t_death *infos);
int				check_meals_sem(t_philo *head, int ac, unsigned int *inputs);
void			error_handling(void);
void			*routine_sem(void *arg);
void			check_arg(int ac);
int				*start_process(t_philo *p, unsigned int *in, t_sema *s, int ac);
void			sem_error_hand(sem_t *semaphore);
void			check_death(unsigned int *inputs);
void			child_process(t_philo *p, unsigned int *in, t_sema *s, int ac);
#endif
