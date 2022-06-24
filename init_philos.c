#include "header.h"


static int	init_info(char **argv, t_philo_info *vars)
{
	int	i;
	int	x;

	i = 1;
	while (argv[i])
	{
		x = 0;
		while (argv[i][x])
			if (!ft_isdigit(argv[i][x++]))
				return (0);
		i++;
	}
	
	vars = malloc(sizeof(t_philo_info) * ft_atoi(argv[1]));

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

