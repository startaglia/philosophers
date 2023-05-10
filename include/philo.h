/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:23:39 by startagl          #+#    #+#             */
/*   Updated: 2023/04/25 10:46:26 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

//	input_err
# define ERR_IN_1 		"INVALID INPUT NUMBER\n"
# define ERR_IN_2 		"INVALID INPUT\n"
# define ERR_IN_3 		"PHILOS NUM MUST BE > 0 AND <= 200\n"
# define ERR_IN_4 		"INPUT MUST BE AN INT\n"
# define ERR_IN_5 		"TIME_TO_DIE, EAT AND SLEEP MUST BE > 60\n"

//	philo_state_message
# define TAKE_FORKS_MSG "TAKE A FORK\n"
# define THINKING_MSG 	"THINKING\n"
# define SLEEPING_MSG 	"SLEEPING\n"
# define EATING_MSG 	"EATING\n"
# define DIED_MSG 		"DIED\n"
//	philo_state_flag
# define SLEEPING 		1
# define THINKING 		2
# define TAKE_FORKS 	3
# define EATING 		4
# define SATED 			5
# define DEAD 			6

typedef struct s_philo
{
	struct s_data		*data;
	pthread_t			th;
	int					id;
	int					eat_cont;
	int					status;
	int					prev_state;
	struct timeval		start_sleep;
	struct timeval		start_eat;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
}	t_philo;

typedef struct s_data
{
	int					philos_num;
	int					meals_nb;
	int					sated_philos;
	t_philo				*philos;
	u_int64_t			time_to_die;
	u_int64_t			time_to_eat;
	u_int64_t			time_to_sleep;
	struct timeval		start_time;
	pthread_mutex_t		*forks;
}	t_data;

//init
int						ft_init_data(t_data *data, int ac, char **av);
int						ft_init_philos(t_data *data, t_philo *philos);
int						init_forks(t_philo *philo, t_data *data);

//	utils
int						ft_atoi(char *str);
int						error(char *str, t_data *data);
int						ft_strcmp(char *s1, char *s2);
void					messages(char *str, t_philo *philo);
void					ft_exit(t_data *data);
int						ft_error(int str);
int						ft_free(t_data *t);

//	time
unsigned long			time_diff(struct timeval action_time);
int						thread_init(t_data *data);

//	checker
int						input_checker(int ac, char **av);

//	actions
int						think(t_philo *philo, int i);
int						take_fork(t_philo *philo, int i);
int						eat(t_philo *philo, int i);
int						sleep_philo(t_philo *philo, int i);
int						dead(t_philo *philo, int i);

//	threads
void					*routine(void *data);
int						do_action(t_philo *philo, int i);
#endif