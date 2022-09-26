/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:28:37 by flouta            #+#    #+#             */
/*   Updated: 2022/06/29 19:29:10 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		take_forks(philo, philo->start_time);
		eating(philo, philo->start_time);
		release_forks(philo);
		sleeping(philo, philo->start_time);
		thinking(philo, philo->start_time);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_philo			*philos;
	unsigned int	*inputs;

	philos = NULL;
	if (ac < 5 || ac > 6)
	{
		printf("Wrong number of arguments\n");
		return (0);
	}
	inputs = parse_input(ac, av);
	if (!inputs)
		return (0);
	philos = init_philos(philos, inputs);
	if (!create_threads(philos, routine))
		return (0);
	while (check_death(philos) == 1 && check_meals(philos, ac) == 1)
		;
	return (0);
}
