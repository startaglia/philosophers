/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:41:36 by startagl          #+#    #+#             */
/*   Updated: 2023/04/20 16:00:23 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

unsigned long	time_diff(struct timeval action_time)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (((now.tv_sec * 1000) + (now.tv_usec / 1000))
		- ((action_time.tv_sec * 1000) + (action_time.tv_usec / 1000)));
}

int	ft_free(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philos_num)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(data->philos[i].l_fork);
		pthread_mutex_destroy(data->philos[i].r_fork);
	}
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
	free(data);
	return (0);
}
