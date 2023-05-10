/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:02:01 by startagl          #+#    #+#             */
/*   Updated: 2023/04/20 16:06:04 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* sleep action */
int	sleep_philo(t_philo *philo, int i)
{
	printf("%lu\t%d\t%s", time_diff(philo[i].data->start_time),
		philo[i].id, SLEEPING_MSG);
	philo[i].prev_state = SLEEPING;
	return (0);
}

/* think action */
int	think(t_philo *philo, int i)
{
	printf("%lu\t%d\t%s", time_diff(philo[i].data->start_time),
		philo[i].id, THINKING_MSG);
	philo[i].prev_state = THINKING;
	return (0);
}

/* take_fork action */
int	take_fork(t_philo *philo, int i)
{
	printf("%lu\t%d\t%s", time_diff(philo[i].data->start_time),
		philo[i].id, TAKE_FORKS_MSG);
	philo[i].prev_state = TAKE_FORKS;
	return (0);
}

/* eat action */
int	eat(t_philo *philo, int i)
{
	printf("%lu\t%d\t%s", time_diff(philo[i].data->start_time),
		philo[i].id, TAKE_FORKS_MSG);
	printf("%lu\t%d\t%s", time_diff(philo[i].data->start_time),
		philo[i].id, EATING_MSG);
	philo[i].prev_state = EATING;
	return (0);
}

/* dead action */
int	dead(t_philo *philo, int i)
{
	printf("%lu\t%d\t%s", time_diff(philo[i].data->start_time),
		philo[i].id, DIED_MSG);
	ft_free(philo->data);
	exit (0);
}
