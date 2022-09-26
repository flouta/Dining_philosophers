/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils-3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:31:36 by flouta            #+#    #+#             */
/*   Updated: 2022/06/29 19:31:37 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(unsigned int duration)
{
	unsigned long	start_time;

	start_time = curr_time();
	while ((curr_time() - start_time) < duration)
	{
		usleep(50);
	}
}

void	ft_printf(t_philo *philo, unsigned long start_time, int i)
{
	unsigned long	now;

	now = curr_time();
	pthread_mutex_lock(&philo->shared_infos->print_mutex);
	if (i == 0)
		printf("[%ld ms] %d has taken a fork\n", now - start_time, \
			philo->number);
	else if (i == 1)
		printf("[%ld ms] %d %sis eating%s\n", now - start_time, \
			philo->number, "\x1B[32m", "\x1B[0m");
	else if (i == 2)
		printf("[%ld ms] %d is sleeping\n", now - start_time, \
			philo->number);
	else if (i == 3)
		printf("[%ld ms] %d is thinking\n", now - start_time, \
			philo->number);
	pthread_mutex_unlock(&philo->shared_infos->print_mutex);
}

int	check_death(t_philo *head)
{
	t_philo			*tmp;
	unsigned int	last_meal;
	unsigned long	start_time;
	unsigned int	i;

	i = 0;
	tmp = head;
	while (i < head->inputs[0])
	{
		pthread_mutex_lock(&tmp->last_meal_m);
		last_meal = curr_time() - tmp->last_meal;
		pthread_mutex_unlock(&tmp->last_meal_m);
		start_time = curr_time() - tmp->start_time;
		if (last_meal >= tmp->inputs[1])
		{
			pthread_mutex_lock(&tmp->shared_infos->print_mutex);
			printf("[%ld ms] %d %sdied%s"\
			, start_time, tmp->number, "\x1B[31m", "\x1B[0m");
			return (-1);
		}
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int	check_meals(t_philo *head, int ac)
{
	t_philo			*tmp;
	unsigned int	number_of_meal;
	unsigned int	i;

	i = 0;
	tmp = head;
	if ((ac -1) == 4)
		return (1);
	if ((ac - 1) == 5 && head->inputs[4] == 0)
		return (-1);
	while (i < head->inputs[0])
	{
		pthread_mutex_lock(&tmp->meals_m);
		number_of_meal = tmp->number_of_meals;
		pthread_mutex_unlock(&tmp->meals_m);
		if (number_of_meal < tmp->inputs[4])
			return (1);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}
