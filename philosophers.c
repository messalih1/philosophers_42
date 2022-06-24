/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messalih <messalih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 21:04:54 by messalih          #+#    #+#             */
/*   Updated: 2022/06/24 21:37:46 by messalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_actions(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->fork);
	ft_print("%ld %d has taken a fork\n", (get_time()
			- philosopher->infos->start), philosopher->index,
		&philosopher->infos->t_pen);
	pthread_mutex_lock(philosopher->next_fork);
	ft_print("%ld %d has taken a fork\n",
		(get_time() - philosopher->infos->start),
		philosopher->index, &philosopher->infos->t_pen);
	ft_print("%ld %d is eating\n", (get_time() - philosopher->infos->start),
		philosopher->index, &philosopher->infos->t_pen);
	philosopher->last_time_eat = get_time() - philosopher->infos->start;
	usleep(philosopher->infos->time_to_eat * 1000);
	pthread_mutex_unlock(&philosopher->fork);
	pthread_mutex_unlock(philosopher->next_fork);
	ft_print("%ld %d is sleeping\n", (get_time() - philosopher->infos->start),
		philosopher->index, &philosopher->infos->t_pen);
	usleep(philosopher->infos->time_to_sleep * 1000);
	ft_print("%ld %d is thinking\n", (get_time() - philosopher->infos->start),
		philosopher->index, &philosopher->infos->t_pen);
}

void	*philosopher(void *philo_info)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)philo_info;
	while (philosopher->infos->number_of_times_each_philosopher_must_eat
		> philosopher->how_many_times_eat++ || philosopher->infos->infini_loop)
	{
		philo_actions(philosopher);
	}
	philosopher->infos->exit++;
	return (NULL);
}

int	create_philos(t_infos *infos, t_philo *philo)
{
	int	x;

	x = 0;
	while (x < infos->number_of_philos)
	{
		philo[x].index = x + 1;
		usleep(100);
		if (pthread_create(&philo[x].t_id, NULL, philosopher, &philo[x]) != 0)
			return (-1);
		x++;
	}
	return (0);
}
