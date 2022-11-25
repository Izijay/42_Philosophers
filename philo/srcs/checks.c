/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:40:50 by mdupuis           #+#    #+#             */
/*   Updated: 2022/02/10 10:48:29 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_philos(int nb)
{
	if (nb > 200)
	{
		write(2, "Error\nThe number of philos must not exceed 200.\n", 48);
		return (0);
	}
	if (nb <= 0 && nb < 1)
	{
		write(2, "Error\n", 6);
		write(2, "The number of Philos must be greater than zero.\n", 48);
		return (0);
	}
	return (1);
}

int	check_args(char **av, t_data *data)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!ft_str_isdigit(av[i]))
		{
			write(2, "Error\nNot a valid number.\n", 26);
			return (0);
		}
		i++;
	}
	if (!parse_args(av, data))
		return (0);
	return (1);
}

int	check_overflows(char **av)
{
	int		i;
	long	tmp;

	i = 0;
	while (av[++i])
	{
		tmp = atoi_philo(av[i]);
		if (tmp > 2147483647 || tmp < -2147483648)
		{
			write(2, "Error\nInvalid number.\n", 22);
			return (0);
		}
	}
	return (1);
}
