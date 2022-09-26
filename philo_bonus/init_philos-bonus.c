/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos-bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 20:59:55 by flouta            #+#    #+#             */
/*   Updated: 2022/07/02 20:59:58 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_philo	*init_head(t_philo *head, t_philo *curr, unsigned int i)
{
	head = curr;
	curr->number = i;
	curr->number_of_meals = 0;
	curr->next = NULL;
	curr->last_meal = curr_time_sem();
	curr->start_time = curr_time_sem();
	curr->prog_start_time = curr_time_sem();
	return (head);
}

t_philo	*init_tmp(t_philo *head, t_philo *curr, t_philo *tmp, unsigned int i)
{
	tmp->next = curr;
	curr->next = NULL;
	curr->number = i;
	curr->number_of_meals = 0;
	curr->last_meal = curr_time_sem();
	curr->start_time = curr_time_sem();
	curr->prog_start_time = curr_time_sem();
	return (head);
}

t_philo	*init_philos_sem(t_philo *head, unsigned int *inputs)
{
	t_philo			*tmp;
	t_philo			*curr;
	unsigned int	i;

	i = 1;
	while (i <= inputs[0])
	{
		tmp = head;
		curr = (t_philo *)malloc(sizeof(t_philo));
		if (!curr)
		{
			printf("OVERFLOW\n");
			pthread_exit(NULL);
		}
		if (head == NULL)
			head = init_head(head, curr, i);
		else
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			head = init_tmp(head, curr, tmp, i);
		}
		i++;
	}
	return (head);
}
