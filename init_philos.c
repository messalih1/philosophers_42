#include "header.h"

 



t_philo_info *init_info(char **argv,int argc)
{
	int i;
	int num_of_philos;
	t_philo_info *ptr;
	
	num_of_philos = ft_atoi(argv[1]);
	i = 0;
	ptr = malloc(sizeof(t_philo_info) * num_of_philos);
	while (i < num_of_philos)
	{
		ptr[i].dead = 0;
		ptr[i].start = get_time();
		ptr[i].time_to_die = ft_atoi(argv[2]);
		ptr[i].time_to_eat = ft_atoi(argv[3]);
		ptr[i].time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			ptr[i].t_must_eat = ft_atoi(argv[5]);		 
        i++;
	}
	return ptr;
}

t_philo *init_philos(char **argv,int argc,t_philo *philos)
{
	t_philo_info *temp;
	t_philo *ptr;
	int i;
	int num_of_philos;

	i = 0;
	num_of_philos = ft_atoi(argv[1]);
	
	ptr = malloc(sizeof(t_philo) * num_of_philos);
    
	temp = init_info(argv,argc);
	
	while (i < num_of_philos)
	{
		if (argc == 5)
			ptr[i].infini_loop = 1;
		else
			ptr[i].infini_loop = temp[0].t_must_eat;
		
        ptr[i].p_info = &temp[i];    
		ptr[i].index = i;
		ptr[i].number_of_philo = ft_atoi(argv[1]);
		pthread_mutex_init(&ptr[i].forks,NULL);
		pthread_mutex_init(&ptr[i].p,NULL);
		i++;
	}
	return ptr;
}






