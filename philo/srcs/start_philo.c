/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:17:34 by mdupuis           #+#    #+#             */
/*   Updated: 2022/01/03 18:17:34 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	time_to_eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->fork[philo->left_f]);
	display(philo->philo_id + 1, "has taken a fork", data, 16);
	pthread_mutex_lock(&data->fork[philo->right_f]);
	display(philo->philo_id + 1, "has taken a fork", data, 16);
	pthread_mutex_lock(&data->last_meal_mutex);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&data->last_meal_mutex);
	display(philo->philo_id + 1, "is eating", data, 9);
	ft_skip_time(data->eat_t);
	pthread_mutex_lock(&data->meal_mutex);
	philo->meal++;
	pthread_mutex_unlock(&data->meal_mutex);
	pthread_mutex_unlock(&data->fork[philo->left_f]);
	pthread_mutex_unlock(&data->fork[philo->right_f]);
}

void	*philo_routine(void *philo_cpy)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)philo_cpy;
	data = philo->data;
	if (philo->philo_id % 2)
		usleep(15000);
	while (1)
	{
		if (!dead_routine(data))
			break ;
		time_to_eat(philo);
		display(philo->philo_id + 1, "is sleeping", data, 11);
		ft_skip_time(data->sleep_t);
		display(philo->philo_id + 1, "is thinking", data, 11);
	}
	return (0);
}

static int	mutex_lock_meal(t_data *data, int i, int *j,
	long long last_meal_cpy)
{
	pthread_mutex_lock(&data->last_meal_mutex);
	if (data->philo[i].last_meal == 0)
		last_meal_cpy = data->philo[i].first_meal;
	else
		last_meal_cpy = data->philo[i].last_meal;
	pthread_mutex_unlock(&data->last_meal_mutex);
	if ((get_time() - last_meal_cpy) >= data->death_t)
	{
		pthread_mutex_lock(&data->death_mutex);
		data->death = 1;
		pthread_mutex_unlock(&data->death_mutex);
		return (display(data->philo[i].philo_id + 1, "died", data, 4));
	}
	pthread_mutex_lock(&data->meal_mutex);
	if (data->philo[i].meal >= data->nb_eat && data->nb_eat != -1)
	{
		pthread_mutex_unlock(&data->meal_mutex);
		if (++(*j) == data->nb - 1)
		{
			data->nb_eated = 1;
			return (0);
		}
	}
	pthread_mutex_unlock(&data->meal_mutex);
	return (1);
}

static void	eat_or_die(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->death == 0 || data->nb_eated == 0)
	{
		i = -1;
		j = 0;
		while (++i < data->nb)
		{
			if (!mutex_lock_meal(data, i, &j, 0))
				return ;
		}
	}
}

int	start_philo(t_data *data)
{
	int		i;
	t_philo	*philo;

	philo = data->philo;
	i = -1;
	data->timestamp = get_time();
	while (++i < data->nb)
	{
		if (pthread_create(&(philo[i].philo_thread), NULL,
				philo_routine, &(philo[i])) != 0)
		{
			write(2, "Error\nCannot create thread\n", 27);
			return (0);
		}
		philo[i].first_meal = get_time();
	}
	eat_or_die(data);
	usleep(1500000);
	i = -1;
	while (++i < data->nb)
		pthread_detach(data->philo[i].philo_thread);
	return (1);
}
