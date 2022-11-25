/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 08:37:37 by mdupuis           #+#    #+#             */
/*   Updated: 2022/02/10 15:35:50 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	parse_args(char **av, t_data *data)
{
	if (!check_overflows(av))
		return (0);
	data->nb = atoi_philo(av[1]);
	data->death_t = atoi_philo(av[2]);
	data->eat_t = atoi_philo(av[3]);
	data->sleep_t = atoi_philo(av[4]);
	if (av[5])
		data->nb_eat = atoi_philo(av[5]);
	else
		data->nb_eat = -1;
	if (!check_philos(data->nb))
		return (0);
	else if (data->sleep_t < 0 || data->eat_t < 0 || data->death_t < 0
		|| data->nb_eat == 0)
	{
		write(2, "Error\nInvalid arguments.\n", 25);
		return (0);
	}
	if (!ft_init_struct(data))
		return (0);
	data->nb_eated = 0;
	if (!ft_init_mutex(data))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	data.death = 0;
	if (ac != 5 && ac != 6)
	{
		write(2, "Error\n./philo needs min 5 and max 6 arguments.\n", 47);
		write(2, "Use: ./philo nb_philo death_t eat_t sleep_t\n", 44);
		write(2, "Last argument may be the minimum nb of meal per philo\n", 54);
		return (1);
	}
	if (!check_args(av, &data))
		return (1);
	if (!start_philo(&data))
		return (1);
	return (0);
}
