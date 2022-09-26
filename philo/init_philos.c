/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:30:05 by flouta            #+#    #+#             */
/*   Updated: 2022/06/29 19:30:07 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo_attr(t_philo *curr, unsigned int i, unsigned int *inputs)
{
	curr->number = i;
	curr->number_of_meals = 0;
	curr->inputs = inputs;
	curr->last_meal = curr_time();
	curr->start_time = curr_time();
	pthread_mutex_init(&curr->fork_mutex, NULL);
	pthread_mutex_init(&curr->last_meal_m, NULL);
	pthread_mutex_init(&curr->meals_m, NULL);
}

t_philo	*init_head(t_philo *c, unsigned int i, unsigned int *in, t_philo *h)
{
	h = c;
	c->next = h;
	init_philo_attr(c, i, in);
	h->shared_infos = malloc(sizeof(t_shared_info));
	pthread_mutex_init(&c->shared_infos->print_mutex, NULL);
	return (h);
}

t_philo	*init_tmp(t_philo *c, unsigned int i, t_philo *h, t_philo *tmp)
{
	tmp->next = c;
	c->next = h;
	init_philo_attr(c, i, h->inputs);
	c->shared_infos = h->shared_infos;
	return (h);
}

t_philo	*init_philos(t_philo *head, unsigned int *inputs)
{
	t_philo			*tmp;
	t_philo			*curr;
	unsigned int	i;

	i = 1;
	while (i++ <= inputs[0])
	{
		tmp = head;
		curr = (t_philo *)malloc(sizeof(t_philo));
		if (!curr)
			exit(0);
		if (head == NULL)
		{
			head = init_head(curr, i, inputs, head);
		}
		else
		{
			while (tmp->next != head)
				tmp = tmp->next;
			init_tmp(curr, i, head, tmp);
		}
	}
	return (head);
}
