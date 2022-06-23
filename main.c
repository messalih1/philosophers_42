#include "header.h"
 
void	check_if_did(t_philo *philo)
{
	int	x;

	x = 0;
	while (x < philo[0].number_of_philo)
	{
		if ((get_time() - philo[x].p_info->start) - philo[x].p_info->last_time_eat
			>= philo[x].p_info->last_time_eat+ philo[x].p_info->time_to_die)
		{
			 
             printf("did\n");
			// pthread_mutex_lock(&philo[x].p);
			break ;
		}
	}
}

int main(int argc, char  *argv[])
{
	printf("\n");
	 
	
	if (argc == 5 || argc == 6)
	{
		t_philo *philos;
		t_philo_info *info;
  
		philos = init_philos(argv, argc, philos);
		circle_philos(philos);
		create_threads(philos,info);
        // check_if_did(philos);


	}
	else
		printf("ERROR");
	return 0;
}
 
 







		


	// struct timeval start, end;
	
	// pthread_mutex_lock(&philos->forks);
	
	// printf("philosopher %d has taken a fork\n",philos->index + 1);
	
	// pthread_mutex_lock(philos->next_forks);
	
 	// gettimeofday(&start, NULL);
	// usleep(philos->p_info->time_to_eat * 1000);
	// printf("philosopher %d has taken a fork\n",philos->index + 1);


	// printf("philosopher %d eating...\n",philos->index + 1);	

	 
	// pthread_mutex_unlock(&philos->forks);
	 
	// pthread_mutex_unlock(philos->next_forks);
	 
	// printf("philosopher %d sleeping...\n",philos->index + 1);
	
	// usleep(philos->p_info->time_to_sleep * 1000);
	
	// gettimeofday(&end, NULL);

	// long seconds = (end.tv_sec - start.tv_sec);
    // long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);

	// philos->time_creation = micros;
	
	// get_time(philos->time_creation,philos);
	// printf("philosopher %d thinking\n",philos->index + 1);