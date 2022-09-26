/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:31:04 by flouta            #+#    #+#             */
/*   Updated: 2022/06/29 19:31:06 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo, unsigned long start_time)
{
	pthread_mutex_lock(&philo->fork_mutex);
	ft_printf(philo, start_time, 0);
	pthread_mutex_lock(&philo->next->fork_mutex);
	ft_printf(philo, start_time, 0);
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->fork_mutex);
	pthread_mutex_unlock(&philo->next->fork_mutex);
}

void	eating(t_philo *philo, unsigned int start_time)
{
	ft_printf(philo, start_time, 1);
	pthread_mutex_lock(&philo->last_meal_m);
	philo->last_meal = curr_time();
	pthread_mutex_unlock(&philo->last_meal_m);
	ft_usleep(philo->inputs[2]);
	pthread_mutex_lock(&philo->meals_m);
	philo->number_of_meals++;
	pthread_mutex_unlock(&philo->meals_m);
}

void	sleeping(t_philo *philo, unsigned int start_time)
{
	ft_printf(philo, start_time, 2);
	ft_usleep(philo->inputs[3]);
}

void	thinking(t_philo *philo, unsigned int start_time)
{
	ft_printf(philo, start_time, 3);
}
