/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philopthread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:00:59 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/10/10 11:49:41 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void*   routine(void *arg)
{
		t_philo	*philo;

		philo = (t_philo *) arg;
		while (!stru()->philo->is_die)
		{
			if (!stru()->philo->is_eat)
				eat(philo);
		}
		return (NULL);
}

void	take_fork(t_philo	*philo)
{
		pthread_mutex_lock(philo->l_fork);
		printf("Philosopher %d take fork\n", philo->n);
		pthread_mutex_lock(philo->r_fork);
		printf("Philosopher %d take fork\n", philo->n);
}

void	free_fork(t_philo *philo)
{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		printf("Philosopher %d is sleeping\n", philo->n);
		sleep(stru()->t_sleep);
		printf("Philosopher %d is thinking\n", philo->n);
}

void	eat(t_philo *philo)
{
	take_fork(philo);
	pthread_mutex_lock(&stru()->lock);
	stru()->philo->is_eat = 1;
	printf("Philosopher %d is eating\n", philo->n);
	usleep(stru()->t_eat);
	stru()->philo->is_eat = 0;
	pthread_mutex_unlock(&stru()->lock);
	free_fork(philo);
}

int init_threads(void)
{
    int i;
    
		i = 0;
    while (++i <= stru()->nb_philo)
    {
				if (pthread_create(&stru()->thread, NULL, &routine, &stru()->philo[i]))
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
