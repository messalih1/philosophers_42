#include "header.h"
 
 

int main(int argc, char  *argv[])
{
	t_philo_info ph;
	t_philo *philos;
	t_philo_info *infos;
	infos = &ph;
	char *error;

	error = init_info_of_philos(argv,argc, infos);
	if(error)
		return(printf("%s\n", error), 0);
	philos = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	infos->start = get_time();
	fill_philos_infos(philos, infos, argv);
	circle_philos(philos); 
	
	
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