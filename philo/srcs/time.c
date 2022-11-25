/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:10:54 by mdupuis           #+#    #+#             */
/*   Updated: 2022/02/10 11:12:01 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_skip_time(int time)
{
	long long	i;

	i = get_time();
	while (1)
	{
		if (get_time() - i >= time)
			break ;
		if (usleep(200) == -1)
		{
			write(2, "Error\nFunction usleep failed.\n", 30);
			return (0);
		}
	}
	return (1);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
