/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_utils_4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 21:00:49 by flouta            #+#    #+#             */
/*   Updated: 2022/07/02 21:00:52 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	check_arg(int ac)
{
	if (ac < 5 || ac > 6)
	{
		printf("Wrong number of arguments\n");
		exit (0);
	}
}

void	sem_error_hand(sem_t *semaphore)
{
	if (semaphore == SEM_FAILED)
	{
		printf("ERROR : Failed to open semphore for empty\n");
		exit (-1);
	}
}

int	*start_process(t_philo *philos, unsigned int *inputs, t_sema *sem, int ac)
{
	t_philo			*philo;
	int				*pids;
	unsigned int	i;

	philo = philos;
	i = 0;
	pids = malloc(sizeof(int) * inputs[0]);
	while (i < inputs[0])
	{
		pids[i] = fork();
		if (pids[i] < 0)
			error_handling();
		if (pids[i] == 0)
		{
			child_process(philo, inputs, sem, ac);
		}
		philo = philo->next;
		i++;
	}
	return (pids);
}

void	check_death(unsigned int *inputs)
{
	unsigned int	i;
	unsigned int	j;
	t_exit_val		exitt;

	i = 0;
	j = 0;
	while (j++ < inputs[0])
	{
		waitpid(-1, &exitt.status, 0);
		if (WIFEXITED(exitt.status))
		{
			exitt.statuscode = WEXITSTATUS(exitt.status);
			if (exitt.statuscode == 0)
				kill(0, SIGINT);
		}
	}
}
