/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:52:36 by startagl          #+#    #+#             */
/*   Updated: 2023/04/20 14:42:16 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	wrong_input(char	*str)
{
	if (str == ERR_IN_2)
		write(2, ERR_IN_2, 14);
	else if (str == ERR_IN_4)
		write(2, ERR_IN_4, 21);
	exit(1);
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *str)
{
	long int	r;
	int			i;

	r = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		wrong_input(ERR_IN_2);
	if (str[i] == '+')
	{
		if (!ft_isdigit(str[i + 1]))
			wrong_input(ERR_IN_2);
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			wrong_input(ERR_IN_2);
		r = r * 10 + (str[i++]) - 48;
	}
	if (r > 2147483647)
		wrong_input(ERR_IN_4);
	return (r);
}
