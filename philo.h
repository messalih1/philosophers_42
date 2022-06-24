/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messalih <messalih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 21:04:02 by messalih          #+#    #+#             */
/*   Updated: 2022/06/24 21:11:15 by messalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_infos {
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	long			start;
	int				dead;
	pthread_mutex_t	t_pen;
	int				x;
	int				infini_loop;
	int				exit;
}	t_infos;

typedef struct s_philsophers{
	pthread_t				t_id;
	pthread_mutex_t			fork;
	pthread_mutex_t			*next_fork;
	t_infos					*infos;
	int						how_many_times_eat;
	long					last_time_eat;
	int						index;
}	t_philo;

void	ft_print(char *str, long time, int id, pthread_mutex_t *pen);
long	get_time(void);
void	fill_infos_philos(t_philo *philo, t_infos *infos);
char	*init_philos(int argc, char **argv, t_infos *infos);
int		ft_isdigit(int i);
int		ft_atoi(const char *str);
void	circle_philos(t_philo *philo);
void	destroy_mutex(t_philo *philo);
void	philo_actions(t_philo *philosopher);
void	*philosopher(void *philo_info);
int		create_philos(t_infos *infos, t_philo *philo);

#endif