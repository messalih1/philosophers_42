/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messalih <messalih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 21:04:57 by messalih          #+#    #+#             */
/*   Updated: 2022/06/24 21:09:37 by messalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int i)
{	
	if (i >= '0' && i <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	number;
	int		sign;

	i = 0;
	number = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\v' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\n' || str[i] == '\f')
		i++;
	if (str[i] == '+')
	{
		sign = 1;
		i++;
	}
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
		number = (number * 10) + (str[i++] - '0');
	return (number * sign);
}

void	ft_print(char *str, long time, int id, pthread_mutex_t *pen)
{
	pthread_mutex_lock(pen);
	printf(str, time, id);
	pthread_mutex_unlock(pen);
}
