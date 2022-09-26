/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:32:13 by flouta            #+#    #+#             */
/*   Updated: 2022/06/29 19:32:29 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_input(const char *str, int i)
{
	if (!str[0])
		return (false);
	while (str[i])
	{
		if (!is_number(str))
		{
			write(1, "ERROR:one of the argument isn't a digit\n", 41);
			return (false);
		}
		i++;
	}
	return (true);
}

unsigned int	curr_time(void)
{
	unsigned long	time;
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	time = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (time);
}
