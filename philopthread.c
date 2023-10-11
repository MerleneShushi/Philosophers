/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philopthread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:00:59 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/10/11 13:53:50 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void*   routine(void *arg)
{
		t_philo	*philo;

		philo = (t_philo *) arg;
		while (!stru()->philo->is_die)
		{
			eat(philo);
		}
		return (NULL);
}

void	take_fork(t_philo	*philo)
{
		pthread_mutex_lock(philo->l_fork);
		printf("%lu %d has taken a fork\n", stru()->start_time, philo->n);
		pthread_mutex_lock(philo->r_fork);
		printf("%lu %d has taken a fork\n", stru()->start_time, philo->n);
}

void	free_fork(t_philo *philo)
{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		printf("%lu %d sleeping\n", stru()->start_time, philo->n);
		sleep(stru()->t_sleep);
		printf("%lu %d thinking\n", stru()->start_time, philo->n);
}

void	eat(t_philo *philo)
{
	take_fork(philo);
	pthread_mutex_lock(&stru()->lock);
	stru()->philo->is_eat = 1;
	printf("%lu %d is eating\n", stru()->start_time, philo->n);
	usleep(stru()->t_eat);
	stru()->philo->is_eat = 0;
	pthread_mutex_unlock(&stru()->lock);
	free_fork(philo);
}

int init_threads(void)
{
    int i;
    
		i = 0;
		stru()->start_time = get_time();
    while (++i <= stru()->nb_philo)
    {
				if (pthread_create(&stru()->thread, NULL, &routine, &philo()[i]))
            return (printf("ERROR CREATE PTHREAD"));
        printf("Pthread %d init\n", i);
				sleep(2);
    }
    i = 0;
    while (++i <= stru()->nb_philo)
    {
        if (pthread_join(stru()->thread, NULL))
            return (1);
        printf("Pthread %d close\n", i);
    }
    return (0);
}
