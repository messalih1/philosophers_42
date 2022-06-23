#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
 
typedef struct infos
{
    long start;

    unsigned int time_to_die;
    unsigned int time_to_eat;
    unsigned int time_to_sleep;
    unsigned int t_must_eat;
    unsigned int take_fork;
    long last_time_eat;
    int dead;
    
}t_philo_info;

typedef struct philo
{
    pthread_t id_of_philo;
    pthread_mutex_t forks;
    pthread_mutex_t *next_forks;
    pthread_mutex_t p;
    t_philo_info *p_info;
    
    int how_many_times_eat;
    int index;
    long time_creation;
    int number_of_philo;
    long end;
    int infini_loop;
    long muts_eat;
    
}t_philo;


void	ft_print(char *str, long time, int id, pthread_mutex_t *pen);
int ft_atoi(const char *str);


t_philo_info *init_info(char **argv,int argc);

long	get_time(void);


// void *philosophers(void *p);
void create_threads(t_philo *philos,t_philo_info *info);

int	ft_atoi(const char *str);
void circle_philos(t_philo *philos);
t_philo *init_philos(char **argv,int argc,t_philo *philos);

#endif