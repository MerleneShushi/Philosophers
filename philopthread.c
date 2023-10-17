/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philopthread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:00:59 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/10/17 19:40:55 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	*control_routine(void *arg)
{
	t_philo	*philo;
	unsigned long	time;

	philo = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&philo->lock);
		pthread_mutex_lock(&stru()->lock);
		if (stru()->philo_eat_count == stru()->nb_philo)
		{
			pthread_mutex_unlock(&stru()->lock);
			break ;
		}
		pthread_mutex_unlock(&stru()->lock);
		pthread_mutex_unlock(&philo->lock);
		pthread_mutex_lock(&philo->lock);
		time = philo->t_philo_die;
		if (((get_time() - stru()->start_time) > time) && !philo->is_eat)
		{
			menssage("died", philo);
			break ;
		}
		pthread_mutex_unlock(&philo->lock);
	}
	pthread_mutex_unlock(&philo->lock);
	return (0);
}

void*	routine(void *arg)
{
		t_philo	*philo;
		
		philo = (t_philo *)arg;
		if (stru()->nb_philo == 1)
		{
			menssage("has taken a fork", philo);
			usleep(stru()->t_die * 1000);
			menssage("dead", philo);
			return (NULL);
		}
		if (pthread_create(&philo->control, NULL, &control_routine, (void *)philo))
			return ((void *)1);
		while (1)
		{
			if (eat(philo))
				break ;
			if (slepping(philo))
				break ;
			if (thinking(philo))
				break ;
		}
		if (pthread_join(philo->control, NULL))
			return ((void *)1);
		return (NULL);
}

int init_threads(void)
{
	int i;

	i = -1;
	stru()->start_time = get_time();
	while (++i < stru()->nb_philo)
	{
		if (pthread_create(&stru()->thread[i], NULL, &routine, &philo()[i]))
			return (printf("ERROR CREATE PTHREAD"));
		usleep(1);
	}
	i = -1;
	while (++i < stru()->nb_philo)
		pthread_join(stru()->thread[i], NULL);
	return (0);
}
