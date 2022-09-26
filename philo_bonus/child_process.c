/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 21:01:04 by flouta            #+#    #+#             */
/*   Updated: 2022/07/02 21:01:06 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	child_process(t_philo *p, unsigned int *in, t_sema *sem, int ac)
{
	pthread_t	th_id;
	t_death		infos;

	infos.inputs = in;
	infos.philo = p;
	infos.print = sem->print;
	infos.ac = ac;
	if (pthread_create(&th_id, NULL, routine_sem, (void *)&infos) != 0)
	{
		printf("Failed to create thread \n");
		exit (1);
	}
	while (true)
	{
		take_forks_sem(&infos, p->start_time, sem->forks);
		eating_sem(&infos, p->start_time);
		release_forks_sem(sem->forks);
		sleeping_sem(&infos, p->start_time);
		thinking_sem(p, p->start_time, sem->print);
	}
}
