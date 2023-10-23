/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philopthread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:00:59 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/10/22 17:12:54 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	all_eat(t_stru *stru)
{
	if (stru->philo_eat_count == stru->nb_philo)
	{
		pthread_mutex_unlock(&stru->lock);
		return (1);
	}
	return (0);
}

void	*control_routine(void *arg)
{
	static int				i;
	unsigned long			time;
	t_stru					*stru;

	stru = (t_stru *)arg;
	while (i <= stru->nb_philo)
	{
		redmutex(1, i, stru->philo);
		if (all_eat(stru))
			break ;
		redmutex(0, i, stru->philo);
		pthread_mutex_lock(&stru->philo[i].lock);
		time = stru->philo[i].t_philo_die;
		if (((get_time() - stru->start_time) > time) && !stru->philo[i].is_eat)
		{
			menssage("died", &stru->philo[i]);
			break ;
		}
		pthread_mutex_unlock(&stru->philo[i].lock);
		i++;
		if (i == stru->nb_philo)
			i = 0;
	}
	pthread_mutex_unlock(&stru->philo[i].lock);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->stru->nb_philo == 1)
	{
		menssage("has taken a fork", philo);
		usleep(philo->stru->t_die * 1000);
		return (NULL);
	}
	while (1)
	{
		if (eat(philo))
			break ;
		if (slepping(philo))
			break ;
		if (thinking(philo))
			break ;
	}
	return (NULL);
}

int	init_threads(t_stru *stru)
{
	int	i;

	i = -1;
	stru->start_time = get_time();
	while (++i < stru->nb_philo)
	{
		if (pthread_create(&stru->thread[i], NULL, &routine, &stru->philo[i]))
			return (printf("ERROR CREATE PTHREAD"));
		usleep(1);
	}
	if (i > 0)
		if (pthread_create(&stru->control, NULL, &control_routine, stru))
			return (1);
	i = -1;
	while (++i < stru->nb_philo)
		pthread_join(stru->thread[i], NULL);
	if (i > 0)
		pthread_join(stru->control, NULL);
	return (0);
}
