/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:01:42 by startagl          #+#    #+#             */
/*   Updated: 2023/04/20 16:14:46 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* think state*/
int	think_state(t_philo *philo)
{
	if (time_diff(philo->start_sleep) >= philo->data->time_to_sleep)
	{
		philo->status = THINKING;
		return (0);
	}
	return (1);
}

/* take forks state, lock l_fork*/
int	take_fork_state(t_philo *philo)
{
	if (pthread_mutex_lock(philo->l_fork) == 0)
		philo->status = TAKE_FORKS;
	return (0);
}

/* eat state, lock r_fork and case one philo*/
int	eat_state(t_philo *philo)
{
	if (philo->data->philos_num == 1)
		philo->status = DEAD;
	else if (pthread_mutex_lock(philo->r_fork) == 0)
	{
		philo->status = EATING;
		gettimeofday(&philo->start_eat, NULL);
		return (0);
	}
	return (0);
}

/* unlock fork, sleep state and inc sated*/
int	sleep_philo_state(t_philo *philo)
{
	if (time_diff(philo->start_eat) >= philo->data->time_to_eat)
	{
		philo->status = SLEEPING;
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		if (philo->data->meals_nb > 0)
		{
			philo->eat_cont++;
			if (philo->eat_cont == philo->data->meals_nb)
			{
				philo->status = SATED;
				philo->data->sated_philos++;
				return (0);
			}
		}
		gettimeofday(&philo->start_sleep, NULL);
		return (0);
	}
	return (1);
}

/* routine funct, set state*/
void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->id % 2)
		usleep(1000);
	while (!0)
	{
		usleep(100);
		if (philo->status == SLEEPING)
			think_state(philo);
		else if (philo->status == THINKING)
			take_fork_state(philo);
		else if (philo->status == TAKE_FORKS)
			eat_state(philo);
		else if (philo->status == EATING)
			sleep_philo_state(philo);
		else if (philo->status == SATED)
			gettimeofday(&philo->start_sleep, NULL);
	}
}
