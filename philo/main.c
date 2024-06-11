/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:13:46 by mamerlin          #+#    #+#             */
/*   Updated: 2024/06/11 17:15:20 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_table(t_philo *phil)
{
	int i;

	i = 0;
	while (i < phil[0].num_of_philos)
	{
		printf("id: %d\t", phil[i].id);
		printf("time_to_die: %zu\t", phil[i].time_to_die);
		printf("time_to_eat: %zu\t", phil[i].time_to_eat);
		printf("time_to_sleep: %zu\t", phil[i].time_to_sleep);
		printf("num_of_philos: %d\t", phil[i].num_of_philos);
		printf("num_times_to_eat: %d\t", phil[i].num_times_to_eat);
		printf("r_fork: %p\t", phil[i].r_fork);
		printf("l_fork: %p\t", phil[i].l_fork);
		printf("write_lock: %p\t", phil[i].write_lock);
		printf("dead_lock: %p\t", phil[i].dead_lock);
		printf("meal_lock: %p\n", phil[i].meal_lock);
		i++;
	}

}

int main(int argc, char **argv)
{
	t_program		program;
	t_philo			philos[PHILO_MAX];

	if (argc < 5 || argc > 6)
	{
		printf("check your input(too many/few)\t");
		return (1);
	}
	if (validation(argc, argv) != 1)
		return (1);
	init_input(argc, argv, philos);
	init_philos(philos, &program, argv);
	print_table(philos);
	return (0);
}
