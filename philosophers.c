#include "header.h"

void *philos_actions(void *arg)// handle if have one philo  
{ 
    t_philo *philos = (t_philo *)arg;
 
	pthread_mutex_lock(&philos->forks);

	ft_print("%ld philosopher %d has taken a fork\n",(get_time() - philos->p_info->start),philos->index + 1,&philos->p);
	
	pthread_mutex_lock(philos->next_forks);

	ft_print("%ld philosopher %d has taken a fork\n",(get_time() - philos->p_info->start),philos->index + 1,&philos->p);
	
	
	ft_print("%ld philosopher %d eating...\n",(get_time() - philos->p_info->start), philos->index + 1,&philos->p);
 
	philos->p_info->last_time_eat = get_time() - philos->p_info->start;
	 philos->p_info->t_must_eat--;
	usleep(philos->p_info->time_to_eat * 1000);
	 
	pthread_mutex_unlock(&philos->forks);
	pthread_mutex_unlock(philos->next_forks);

    ft_print("%ld %d is sleeping\n", (get_time() - philos->p_info->start), philos->index + 1,&philos->p);
	usleep(philos->p_info->time_to_sleep * 1000);
	ft_print("%ld %d is thinking\n", (get_time() - philos->p_info->start), philos->index + 1,&philos->p);
    
	
    
	
}

void *philosophers(void *p) 
{
	struct philo *philos;

	philos = (struct philo *)p;

	 
	while (philos->infini_loop )  
    {	
		if(philos->p_info->t_must_eat == 0)
			exit(0);						
        if ((get_time() - philos->p_info->start) - philos->p_info->last_time_eat >=  philos->p_info->time_to_die + philos->p_info->last_time_eat)
        {
            printf("did %d %ld\n", philos->index  + 1, (get_time() - philos->p_info->start) - philos->p_info->last_time_eat);
            exit(0);
        }
		else if(philos[0].number_of_philo == 1)
		{
			ft_print("%ld philosopher %d has taken a fork\n",(get_time() - philos->p_info->start),philos->index + 1,&philos->p);
			exit(0);
		}
		philos_actions(philos);
    }
	return NULL;
}

void create_threads(t_philo *philos,t_philo_info *info)
{
	int i = 0;
	
	while ( i < philos[0].number_of_philo)
	{
		pthread_create(&philos[i].id_of_philo,NULL,philosophers,(void*)&philos[i]);
		usleep(100);
		i++;
	}
	i = 0;
	while ( i < philos[0].number_of_philo)
	{
		pthread_join(philos[i].id_of_philo, NULL);
		i++;
	}

    i = 0;

    // while (i < 5)
    // {
    //     printf("philos %d : %ld\n",i + 1, philos[i].p_info->last_time_eat);
    //     i++;
    // }
    

}