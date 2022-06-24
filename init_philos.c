#include "header.h"


static int	init_info(char **argv, t_philo_info *vars)
{
	int	i;
	int	x;
	int num_of_philos;

	i = 1;
	while (argv[i])
	{
		x = 0;
		while (argv[i][x])
			if (!ft_isdigit(argv[i][x++]))
				return (0);
		i++;
	}
	num_of_philos = ft_atoi(argv[1]);
 	vars->start = get_time();
	vars->time_to_die = ft_atoi(argv[2]);
	vars->time_to_eat = ft_atoi(argv[3]);
	vars->time_to_sleep = ft_atoi(argv[4]);
	if (ft_atoi(argv[1]) <= 0 || vars->time_to_die <= 0
		|| vars->time_to_eat <= 60 || vars->time_to_sleep <= 0)
		return (0);
	return (1);
}
 

char *init_info_of_philos(char **argv,int argc,t_philo_info *vars)
{
	// vars->dead = 0;
	// vars->exit = 0;
	if (argc < 5 || argc > 6)
		return ("invalid argumments.");
	if(init_info(argv, vars) == 0)
		return "error";
 
	
	return NULL;

}

void	fill_philos_infos(t_philo *philos, t_philo_info *infos, char **argv)
{
	int i;
	int num_of_ph;

	num_of_ph = ft_atoi(argv[1]);
	i = 0;
	while (i  < num_of_ph)
	{
		philos[i].p_info = infos;
		philos[i].number_of_philo = num_of_ph;
		philos[i].index = i;
		if (argv[5] == NULL)
		{
			philos[i].infini_loop = 1;
			philos[i].p_info->muts_eat = 0;
		}
		else
			philos[i].p_info->muts_eat =  ft_atoi(argv[5]);
		i++;
	}
	

}
