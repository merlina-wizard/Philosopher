/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:16:11 by mamerlin          #+#    #+#             */
/*   Updated: 2024/06/13 12:25:30 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	milltime(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	init_input(char **argv, t_philo *philos)
{
	philos->num_of_philos = ft_atoi(argv[1]);
	philos->time_to_die = ft_atoi(argv[2]);
	philos->time_to_eat = ft_atoi(argv[3]);
	philos->time_to_sleep = ft_atoi(argv[4]);
		if (argv[5])
			philos->num_times_to_eat = ft_atoi(argv[5]);
		else
			philos->num_times_to_eat = -1;
}

void	init_philos(t_philo *philos, t_program *program, pthread_mutex_t *forks,char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		init_input(argv, &philos[i]);
		philos[i].start_time = milltime();
		philos[i].last_meal = milltime();
		philos[i].write_lock = &program->write_lock;
		philos[i].dead_lock = &program->dead_lock;
		philos[i].meal_lock = &program->meal_lock;
		philos[i].dead = &program->dead_flag;
		philos[i].l_fork = &forks[i];
		if (i == 0)
			philos[i].r_fork = philos[philos[0].num_of_philos - 1].l_fork;
		else
			philos[i].r_fork = philos[i - 1].l_fork;
		i++;
	}
}

void	init_prog(t_program *program, t_philo *philos)
{
	program->dead_flag = 0;
	program->philos = philos;
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
	pthread_mutex_init(&program->write_lock, NULL);
}

void init_forks(pthread_mutex_t *forks, int philo_num)
{
	int i;

	i = 0;
	while(i < philo_num)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}
