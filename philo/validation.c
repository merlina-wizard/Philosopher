/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:15:21 by mamerlin          #+#    #+#             */
/*   Updated: 2024/06/11 15:12:39 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_atoi(const char *str)
{
	int			i;
	long long	result;
	int			sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] != '\0') && (str[i] >= '0' && str[i] <= '9'))
	{
		result = ((str[i] - 48) + (result * 10));
		i++;
	}
	return (result * sign);
}

int	isnum(char *save)
{
	int	i;

	i = 0;
	while (save[i] == 32)
		i++;
	if (save[i] == '+' || save[i] == '-')
	{
		if (save[i + 1] == '\0')
			return (0);
		i++;
	}
	while (save[i] >= '0' && save[i] <= '9')
		i++;
	if (save[i] == '\0')
		return (1);
	return (0);
}

int	validation(int argc, char **mat)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!isnum(mat[i]))
			return (write(1, "only numbers allowed\n", 21));
		if (i == 1 && ft_atoi(mat[i]) > 200)
			return (write(1, "too many philo\n", 16));
		if (ft_atoi(mat[i]) <= 0)
			return (write(1, "check the input\n", 16));
		i++;
	}
	return (1);
}
