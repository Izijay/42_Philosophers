/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 08:24:21 by mdupuis           #+#    #+#             */
/*   Updated: 2022/02/10 13:50:59 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				philo_id;
	int				right_f;
	int				left_f;
	int				meal;
	long long		last_meal;
	long long		first_meal;
	struct s_data	*data;
	pthread_t		philo_thread;

}					t_philo;

typedef struct s_data
{
	int				nb;
	int				nb_eat;
	int				death;
	int				eat_t;
	int				death_t;
	int				sleep_t;
	int				nb_eated;
	long long		timestamp;
	t_philo			philo[200];
	pthread_mutex_t	fork[200];
	pthread_mutex_t	print;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	mealed;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	last_meal_mutex;
}					t_data;

int				ft_str_isdigit(char *str);
int				ft_init_mutex(t_data *data);
int				ft_init_struct(t_data *data);
int				check_philos(int nb);
int				check_args(char **av, t_data *data);
int				parse_args(char **av, t_data *data);
int				check_overflows(char **av);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				display(int id, char *str_display, t_data *data, int len);
long long		get_time(void);
int				ft_skip_time(int time);
long long int	atoi_philo(const char *str);
int				start_philo(t_data *data);
int				dead_routine(t_data *data);

#endif