/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messalih <messalih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 21:03:57 by messalih          #+#    #+#             */
/*   Updated: 2022/06/24 21:09:27 by messalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	circle_philos(t_philo *philo)
{
	int	x;

	x = 0;
	while (x < philo->infos->number_of_philos)
	{
		philo[x].how_many_times_eat = 0;
		pthread_mutex_init(&philo[x].fork, NULL);
		if (x == philo->infos->number_of_philos - 1)
			philo[x].next_fork = &philo[0].fork;
		else
			philo[x].next_fork = &philo[x + 1].fork;
		x++;
	}
}

void	destroy_mutex(t_philo *philo)
{
	int	x;

	x = 0;
	while (x < philo->infos->number_of_philos)
	{
		pthread_mutex_destroy(&philo[x].fork);
		pthread_detach(philo[x].t_id);
		x++;
	}
	free(philo);
}
