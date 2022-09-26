/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 21:00:10 by flouta            #+#    #+#             */
/*   Updated: 2022/07/02 21:00:13 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	unsigned int	*inputs;
	t_philo			*philos;
	t_sema			semaphores;
	int				*pids;

	philos = NULL;
	pids = NULL;
	check_arg(ac);
	inputs = parse_input(ac, av);
	if (!inputs)
		return (0);
	sem_unlink("/fork");
	sem_unlink("/print");
	semaphores.forks = sem_open("/fork", O_CREAT | O_EXCL, 0644, inputs[0]);
	sem_error_hand(semaphores.forks);
	semaphores.print = sem_open("/print", O_CREAT | O_EXCL, 0644, 1);
	sem_error_hand(semaphores.print);
	philos = init_philos_sem(philos, inputs);
	pids = start_process(philos, inputs, &semaphores, ac);
	check_death(inputs);
	return (0);
}
