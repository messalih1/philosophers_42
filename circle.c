#include "header.h"


// create ci
void circle_philos(t_philo *philos)
{
	int i = 0;

	while (i < philos[0].number_of_philo)// 0
	{
        
		if (i == philos->number_of_philo - 1)
			philos[i].next_forks = &philos[0].forks;
		else
			philos[i].next_forks = &philos[i + 1].forks;// create another fork
		i++;
	}


	 	 	
}
