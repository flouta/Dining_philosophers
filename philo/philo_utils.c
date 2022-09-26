/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:30:37 by flouta            #+#    #+#             */
/*   Updated: 2022/06/29 19:30:41 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_number(const char num[])
{
	int	i;

	i = 0;
	if (!num[0])
		return (false);
	if (num[0] == '+' && num[i + 1] != '\0')
		i = 1;
	while (num[i] != 0)
	{
		if (!ft_isdigit(num[i]))
			return (false);
		i++;
	}
	return (true);
}

unsigned int	ft_atoi(const char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	if (str[0] == '-')
	{
		printf("ERROR : negative input\n");
		return (-1);
	}
	if ((str[0] == '+'))
		i++;
	if (!check_input(str, 0))
		return (-1);
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] >= '0' && str[i] <= '9' )
		result = (result * 10) + (str[i++] - '0');
	return (result);
}

bool	send_odd(pthread_t th_id[], t_philo *philos, void *routine(void *))
{
	unsigned int	i;
	t_philo			*tmp;

	i = -1;
	tmp = philos;
	while (++i < philos->inputs[0])
	{
		if (i % 2)
		{
			tmp = tmp->next;
			continue ;
		}
		if (pthread_create(&th_id[i], NULL, routine, (void *)tmp) != 0)
		{
			printf("Failed to create thread \n");
			return (false);
		}
		usleep(50);
		tmp = tmp->next;
	}
	return (true);
}

bool	send_even(pthread_t th_id[], t_philo *philos, void *routine(void *))
{
	unsigned int	i;
	t_philo			*tmp;

	i = -1;
	tmp = philos;
	while (++i < philos->inputs[0])
	{
		if (!(i % 2))
		{
			tmp = tmp->next;
			continue ;
		}
		if (pthread_create(&th_id[i], NULL, routine, (void *)tmp) != 0)
		{
			printf("Failed to create thread \n");
			return (false);
		}
		usleep(50);
		tmp = tmp->next;
	}
	return (true);
}

bool	create_threads(t_philo *philos, void *routine(void *))
{
	pthread_t		*th_id;

	th_id = malloc(sizeof(pthread_t) * philos->inputs[0]);
	if (!send_odd(th_id, philos, routine))
		return (false);
	if (!send_even(th_id, philos, routine))
		return (false);
	free(th_id);
	return (true);
}
