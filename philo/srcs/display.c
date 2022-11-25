/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:17:14 by mdupuis           #+#    #+#             */
/*   Updated: 2022/01/03 18:17:14 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	display(int id, char *str_display, t_data *data, int len)
{
	pthread_mutex_lock(&data->print);
	write(1, "[[ ", 3);
	ft_putnbr_fd(((long long)get_time() - data->timestamp), 1);
	write(1, " ]] --- Philo ", 14);
	ft_putnbr_fd(id, 1);
	write(1, " ", 1);
	write(1, str_display, len);
	write(1, "\n", 1);
	if (ft_strncmp("died", str_display, 4) != 0)
	{
		pthread_mutex_unlock(&data->print);
		return (1);
	}
	return (0);
}
