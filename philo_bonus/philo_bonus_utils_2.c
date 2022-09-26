/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 21:00:35 by flouta            #+#    #+#             */
/*   Updated: 2022/07/02 21:00:37 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	take_forks_sem(t_death *infos, unsigned long s_t, sem_t *f)
{
	sem_wait(f);
	ft_printf_sem(infos->philo, s_t, 0, infos->print);
	sem_wait(f);
	ft_printf_sem(infos->philo, s_t, 0, infos->print);
}

void	eating_sem(t_death *infos, unsigned int start_time)
{
	ft_printf_sem(infos->philo, start_time, 1, infos->print);
	infos->philo->last_meal = curr_time_sem();
	ft_usleep_sem(infos->inputs[2]);
	infos->philo->number_of_meals++;
}

void	release_forks_sem(sem_t *forks)
{
	sem_post(forks);
	sem_post(forks);
}

void	sleeping_sem(t_death *infos, unsigned int s_t)
{
	ft_printf_sem(infos->philo, s_t, 2, infos->print);
	ft_usleep_sem(infos->inputs[3]);
}

void	thinking_sem(t_philo *philo, unsigned int start_time, sem_t *print)
{
	ft_printf_sem(philo, start_time, 3, print);
}
