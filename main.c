/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messalih <messalih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 21:03:39 by messalih          #+#    #+#             */
/*   Updated: 2022/06/24 21:30:05 by messalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_philo_dead(t_philo *philo)
{
	int	x;

	x = 0;
	while (x < philo[0].infos->number_of_philos)
	{
		if ((get_time() - philo[x].infos->start) - philo[x].last_time_eat
			>= philo[x].last_time_eat + philo[x].infos->time_to_die)
		{
			philo[x].infos->dead = 1;
			ft_print("%ld %d died\n", (get_time() - philo[x].infos->start),
				philo[x].index, &philo[x].infos->t_pen);
			pthread_mutex_lock(&philo[x].infos->t_pen);
			break ;
		}
		if (philo[x].infos->exit == philo[x].infos->number_of_philos)
			break ;
		x++;
		if (philo[0].infos->number_of_philos == x)
			x = 0;
	}
}

int	main(int argc, char **argv)
{
	char	*check;
	t_infos	infos;
	t_philo	*philos;

	check = init_philos(argc, argv, &infos);
	if (check)
		return (printf("%s", check), 1);
	philos = malloc(sizeof(t_philo) * (infos.number_of_philos));
	infos.start = get_time();
	fill_infos_philos(philos, &infos);
	circle_philos(philos);
	if (create_philos(&infos, philos))
		return (printf("ERROR: can't create a thread\n"), 1);
	check_philo_dead(philos);
	destroy_mutex(philos);
	return (0);
}
