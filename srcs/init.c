/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:46:56 by startagl          #+#    #+#             */
/*   Updated: 2023/04/25 10:46:40 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_forks(t_philo *philo, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philos_num)
	{
		philo[i].l_fork = data->forks + i;
		if (i == data->philos_num - 1)
			philo[i].r_fork = data->forks;
		else
			philo[i].r_fork = (data->forks + i + 1);
	}
	i = -1;
	while (++i < data->philos_num)
		pthread_create(&philo[i].th, NULL, &routine, philo + i);
	return (0);
}

int	ft_init_philos(t_data *data, t_philo *philos)
{
	int	i;

	i = -1;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philos_num);
	if (!data->forks)
		return (1);
	while (++i < data->philos_num)
	{
		philos[i].data = data;
		philos[i].id = i + 1;
		philos[i].eat_cont = 0;
		philos[i].status = THINKING;
		philos[i].prev_state = SLEEPING;
		pthread_mutex_init(data->forks + i, NULL);
		gettimeofday(&philos[i].start_sleep, NULL);
	}
	init_forks(data->philos, data);
	return (0);
}

int	ft_init_data(t_data *data, int ac, char **av)
{
	data->philos_num = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if ((data->time_to_die < 60)
		|| (data->time_to_eat < 60)
		|| (data->time_to_sleep < 60))
	{
		write(2, ERR_IN_5, 40);
		free(data);
		return (1);
	}
	data->meals_nb = -1;
	data->sated_philos = 0;
	gettimeofday(&data->start_time, NULL);
	if (ac == 6)
		data->meals_nb = ft_atoi(av[5]);
	data->philos = malloc(sizeof(t_philo) * data->philos_num);
	if (!data->philos)
		return (1);
	if (ft_init_philos(data, data->philos))
		return (1);
	return (0);
}
