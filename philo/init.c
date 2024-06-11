/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:16:11 by mamerlin          #+#    #+#             */
/*   Updated: 2024/06/11 17:18:55 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_input(int argc, char **argv, t_philo *philos)
{
	int i;

	i = 0;
	philos[0].num_of_philos= 1;
	while(i < philos[0].num_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].num_of_philos = ft_atoi(argv[1]);
		philos[i].time_to_die = ft_atoi(argv[2]);
		philos[i].time_to_eat = ft_atoi(argv[3]);
		philos[i].time_to_sleep = ft_atoi(argv[4]);
		if (argc == 5 && argc == 6)
			philos[i].num_times_to_eat = ft_atoi(argv[5]);
		else
			philos[i].num_times_to_eat = -1;
		i++;
	}
	return (0);
}

void	init_philos(t_philo *philos, t_program *program, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		pthread_mutex_init(philos[i].l_fork, NULL);
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		//philos[i].start_time = get_current_time();
		//philos[i].last_meal = get_current_time();
		philos[i].write_lock = &program->write_lock;
		philos[i].dead_lock = &program->dead_lock;
		philos[i].meal_lock = &program->meal_lock;
		philos[i].dead = &program->dead_flag;
		if (i == 0)
			philos[i].r_fork = philos[philos[0].num_of_philos - 1].l_fork;
		else
			philos[i].r_fork = philos[i - 1].l_fork;
		i++;
	}
}
