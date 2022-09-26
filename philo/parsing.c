/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:29:38 by flouta            #+#    #+#             */
/*   Updated: 2022/06/29 19:29:40 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

unsigned int	*parse_input(int ac, char **av)
{
	int				i;
	int				a;
	unsigned int	*inputs;

	i = 0;
	a = 0;
	inputs = (unsigned int *)malloc(sizeof(unsigned int) * (ac - 1));
	if (!inputs)
		return (NULL);
	while (i < (ac -1))
	{
		a = ft_atoi(av[i + 1]);
		if (a == -1)
			return (NULL);
		inputs[i] = a;
		if ((i == 0 && (inputs[0] > 512 || inputs[i] == 0)) \
			|| (i != 0 && i != (ac -1) && inputs[i] > 1000000))
			return (NULL);
		i++;
	}
	return (inputs);
}
