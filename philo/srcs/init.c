/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:47:54 by mdupuis           #+#    #+#             */
/*   Updated: 2022/02/10 13:50:23 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_init_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->death_mutex, NULL) != 0)
	{
		write(2, "Error\nDeath mutex init failed\n", 30);
		return (0);
	}
	if (pthread_mutex_init(&data->mealed, NULL) != 0)
	{
		write(2, "Error\nMealed mutex init failed\n", 31);
		return (0);
	}
	if (pthread_mutex_init(&data->meal_mutex, NULL) != 0)
	{
		write(2, "Error\nMeal mutex init failed\n", 29);
		return (0);
	}
	if (pthread_mutex_init(&data->last_meal_mutex, NULL) != 0)
	{
		write(2, "Error\nLast_meal mutex init failed\n", 34);
		return (0);
	}
	return (1);
}

int	ft_init_struct(t_data *data)
{
	int	i;

	i = data->nb - 1;
	while (i >= 0)
	{
		if (pthread_mutex_init(&data->fork[i], NULL) != 0)
		{
			write(2, "Error\nFork mutex init failed.\n", 30);
			return (0);
		}
		data->philo[i].philo_id = i;
		data->philo[i].data = data;
		data->philo[i].left_f = i;
		data->philo[i].right_f = ((data->philo[i].philo_id + 1) % data->nb);
		data->philo[i].first_meal = 0;
		data->philo[i].last_meal = 0;
		data->philo[i].meal = 0;
		i--;
	}
	if (pthread_mutex_init(&data->print, NULL) != 0)
	{		
		write(2, "Error\nPrint mutex init failed.\n", 31);
		return (0);
	}
	return (1);
}
