/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:26:14 by startagl          #+#    #+#             */
/*   Updated: 2023/04/25 10:39:41 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

/* print action, control dead state and set prev status*/
int	do_action(t_philo *philo, int i)
{
	if (philo->eat_cont != 0
		&& philo->data->sated_philos == philo->data->philos_num)
	{
		printf("\tALL PHILOS ARE SATED\n");
		ft_free(philo->data);
		exit (0);
	}
	if (time_diff(philo[i].start_sleep) >= philo[i].data->time_to_die)
		philo[i].status = DEAD;
	if (philo[i].prev_state != philo[i].status)
	{
		if (philo[i].status == SLEEPING)
			sleep_philo(philo, i);
		else if (philo[i].status == THINKING)
			think(philo, i);
		else if (philo[i].status == TAKE_FORKS)
			take_fork(philo, i);
		else if (philo[i].status == EATING)
			eat(philo, i);
		else if (philo[i].status == DEAD)
			dead(philo, i);
	}
	return (1);
}

/* check input value*/
int	input_checker(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		write(2, ERR_IN_1, 21);
		return (1);
	}
	if (ft_atoi(av[1]) < 1 || ft_atoi(av[1]) > 200)
	{
		write(2, ERR_IN_3, 32);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;
	int		i;

	if (input_checker(ac, av))
		exit(1);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (1);
	if (ft_init_data(data, ac, av))
		return (1);
	while (!0)
	{
		i = -1;
		while (++i < data->philos_num)
			do_action(data->philos, i);
	}
	ft_free(data);
	return (0);
}
