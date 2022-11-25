/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:47:46 by mdupuis           #+#    #+#             */
/*   Updated: 2022/02/08 14:25:20 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	dead_routine(t_data *data)
{
	pthread_mutex_lock(&data->death_mutex);
	if (data->death == 1)
	{
		pthread_mutex_unlock(&data->death_mutex);
		return (0);
	}
	pthread_mutex_unlock(&data->death_mutex);
	pthread_mutex_lock(&data->mealed);
	if (data->nb_eated == 1)
	{
		pthread_mutex_unlock(&data->mealed);
		return (0);
	}
	pthread_mutex_unlock(&data->mealed);
	return (1);
}
