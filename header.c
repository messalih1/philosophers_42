#include "header.h"

  int	ft_isdigit(int c)
{
	while (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}
int	ft_atoi(const char *str)
{
	int		i;
	unsigned long		nbr;
	int		n;

	i = 0;
	nbr = 0;
	n = 0;
	while (str[i] != '\0' && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] != '\0' && str[i] == '-')
	{
		n = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		nbr = (nbr * 10) + (str[i++] - '0');
	if (n == 1)
		return (-nbr);
	return (nbr);
}

void	ft_print(char *str, long time, int id, pthread_mutex_t *pen)
{
	pthread_mutex_lock(pen);
	printf(str, time, id);
	pthread_mutex_unlock(pen);
}