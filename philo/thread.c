/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:08:10 by mamerlin          #+#    #+#             */
/*   Updated: 2024/06/12 20:16:43 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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


