/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:32:58 by flouta            #+#    #+#             */
/*   Updated: 2022/06/29 19:33:00 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdio.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>

typedef struct s_shared_info
{
	pthread_mutex_t	print_mutex;	
}	t_shared_info;	
typedef struct s_philo
{
	unsigned int	*inputs;
	int				number;
	unsigned int	number_of_meals;
	unsigned long	last_meal;
	unsigned long	start_time;
	pthread_mutex_t	fork_mutex;
	pthread_mutex_t	last_meal_m;
	pthread_mutex_t	meals_m;	
	t_shared_info	*shared_infos;
	struct s_philo	*next;
}	t_philo;	
unsigned int	ft_atoi(const char *str);
unsigned int	*parse_input(int ac, char **av);
t_philo			*init_philos(t_philo *head, unsigned int *inputs);
void			ft_printf(t_philo *philo, unsigned long start_time, int i);
unsigned int	curr_time(void);
void			ft_usleep(unsigned int duration);
int				check_death(t_philo *head);
int				check_meals(t_philo *head, int ac);
bool			create_threads(t_philo *philos, void *routine(void *));
void			take_forks(t_philo *philo, unsigned long start_time);
void			release_forks(t_philo *philo);
void			eating(t_philo *philo, unsigned int start_time);
void			sleeping(t_philo *philo, unsigned int start_time);
void			thinking(t_philo *philo, unsigned int start_time);
int				ft_isdigit(int c);
void			set_time(t_philo *philo, unsigned int start_time);
bool			is_number(const char num[]);
unsigned int	ft_atoi(const char *str);
bool			check_input(const char *str, int i);
#endif
