/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messalih <messalih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 21:03:43 by messalih          #+#    #+#             */
/*   Updated: 2022/06/24 21:11:04 by messalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

static int	init_all_args(char **argv, t_infos *vars)
{
	int	i;
	int	x;

	i = 1;
	while (argv[i])
	{
		x = 0;
		while (argv[i][x])
			if (!ft_isdigit(argv[i][x++]))
				return (-1);
		i++;
	}
	vars->number_of_philos = ft_atoi(argv[1]);
	vars->time_to_die = ft_atoi(argv[2]);
	vars->time_to_eat = ft_atoi(argv[3]);
	vars->time_to_sleep = ft_atoi(argv[4]);
	vars->infini_loop = 0;
	if (argv[5] == NULL)
	{
		vars->infini_loop = 1;
		vars->number_of_times_each_philosopher_must_eat = 0;
	}
	else
		vars->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	return (0);
}

static int	check_params(t_infos *vars)
{
	if (vars->number_of_philos <= 0 || vars->time_to_die <= 0
		|| vars->time_to_eat <= 60 || vars->time_to_sleep <= 0)
		return (-1);
	return (0);
}

char	*init_philos(int argc, char **argv, t_infos *infos)
{
	infos->dead = 0;
	infos->exit = 0;
	if (argc < 5 || argc > 6)
		return ("inalid argummants.");
	if (init_all_args(argv, infos) == -1)
		return ("Error");
	if (check_params(infos) == -1)
		return ("Error");
	return (NULL);
}

void	fill_infos_philos(t_philo *philo, t_infos *infos)
{
	int	x;

	x = 0;
	while (x < infos->number_of_philos)
	{
		philo[x].infos = infos;
		x++;
	}
}
