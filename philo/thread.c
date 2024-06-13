/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:08:10 by mamerlin          #+#    #+#             */
/*   Updated: 2024/06/13 13:13:37 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print(char *str, t_philo *philo, int id)
{
	size_t time;

	pthread_mutex_lock(philo->write_lock);
	time = milltime() - philo->start_time;
	if (!dead(philo))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}
void	dream(t_philo *philo)
{
	print("is sleeping", philo, philo->id);
	usleep(philo->time_to_sleep);
}

void	think(t_philo *philo)
{
	print("is thinking", philo, philo->id);
}

void eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print("has taken a fork", philo, philo->id);
	pthread_mutex_lock(philo->l_fork);
	print("has taken a fork", philo, philo->id);
	philo->eating = 1;
	print("is eating", philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = milltime();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	usleep(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void *routine(void *ptr)
{
	t_philo *philo;


	philo = (t_philo *)ptr;
	while (!dead_loop(philo))
	{
		eat(philo);
		dream(philo);
		think(philo);
	}
	return (ptr);
}

void	create_thr(t_program *prog, pthread_mutex_t	forks)
{
	pthread_mutex_t obv;
	int i;

	if(pthread_create(&obv, NULL, &monitor, prog->philos) != 0)
		destroy_all("error creation thread!", prog, forks);
	i = 0;
	while (i < prog->philos[0].num_of_philos)
	{
		if(pthread_create(&prog->philos[i].thread, NULL, &routine, &prog->philos[i]) != 0)
			destroy_all("error creation thread!", prog, forks);
			i++;
	}
	i = 0;
	if(pthread_join(&obv, NULL) != 0)
		destroy_all("error creation thread!", prog, forks);
	while (i < prog->philos[0].num_of_philos)
	{
		if (pthread_join(prog->philos[i].thread, NULL) != 0)
			destroy_all("error join thread!", prog, forks);
		i++;
	}
	return(0);
}
int cacca pupu (te, nono tu)
	return


