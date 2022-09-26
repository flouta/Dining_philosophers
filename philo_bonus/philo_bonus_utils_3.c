/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_utils_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 21:01:26 by flouta            #+#    #+#             */
/*   Updated: 2022/07/02 21:01:28 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

unsigned int	curr_time_sem(void)
{
	unsigned long	time;
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	time = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (time);
}

void	ft_usleep_sem(unsigned int duration)
{
	unsigned long	start_time;

	start_time = curr_time_sem();
	while ((curr_time_sem() - start_time) < duration)
	{
		usleep(50);
	}
}

void	ft_printf_sem(t_philo *p, unsigned long s_t, int i, sem_t *print)
{
	unsigned long	now;

	now = curr_time_sem();
	sem_wait (print);
	if (i == 0)
		printf("[%ld ms] %d has taken a fork\n", now - s_t, \
			p->number);
	else if (i == 1)
		printf("[%ld ms] %d %sis eating%s\n", now - s_t, \
			p->number, "\x1B[32m", "\x1B[0m");
	else if (i == 2)
		printf("[%ld ms] %d is sleeping\n", now - s_t, \
			p->number);
	else if (i == 3)
		printf("[%ld ms] %d is thinking\n", now - s_t, \
			p->number);
	sem_post (print);
}

void	error_handling(void)
{
	perror ("ERROR");
	exit (0);
}

void	*routine_sem(void *arg)
{
	t_death	*infos;

	infos = (t_death *)arg;
	while (1)
	{
		if (curr_time_sem() - infos->philo->last_meal >= infos->inputs[1])
		{
			sem_wait (infos->print);
			printf("[%ld ms] %d %sdied%s", curr_time_sem() - \
			infos->philo->start_time, infos->philo->number, \
			"\x1B[31m", "\x1B[0m");
			exit(0);
		}
		if ((infos->ac - 1) == 5 && infos->philo->number_of_meals >= \
		infos->inputs[4])
			exit (2);
		usleep (500);
	}
	return (NULL);
}
