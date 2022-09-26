/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 21:01:16 by flouta            #+#    #+#             */
/*   Updated: 2022/07/02 21:01:19 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

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
