/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:13:52 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/10/21 22:06:56 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	redmutex(int i, int p, t_philo *philo)
{
	if (i == 1)
	{
		pthread_mutex_lock(&philo[p].lock);
		pthread_mutex_lock(&philo[p].stru->lock);
	}
	else if (i == 0)
	{
		pthread_mutex_unlock(&philo[p].stru->lock);
		pthread_mutex_unlock(&philo[p].lock);
	}
	else if (i == 4)
	{
		pthread_mutex_unlock(&philo->stru->lock);
		pthread_mutex_lock(&philo->stru->lock);
	}
}

void	redmutex2(int i, t_philo *philo)
{
	if (i == 1)
	{
		pthread_mutex_lock(&philo->lock);
		pthread_mutex_lock(&philo->stru->lock);
	}
	else if (i == 0)
	{
		pthread_mutex_unlock(&philo->stru->lock);
		pthread_mutex_unlock(&philo->lock);
	}
	else if (i == 2)
	{
		pthread_mutex_lock(&philo->stru->lock);
		pthread_mutex_lock(&philo->stru->message);
	}
	else if (i == 3)
	{
		pthread_mutex_unlock(&philo->stru->message);
		pthread_mutex_unlock(&philo->stru->lock);
	}
	else if (i == 4)
	{
		pthread_mutex_unlock(&philo->stru->lock);
		pthread_mutex_lock(&philo->stru->lock);
	}
}

void	free_destroy(t_stru *stru)
{
	int	i;

	i = -1;
	while (++i < stru->nb_philo)
	{
		pthread_mutex_destroy(&stru->philo[i].lock);
		pthread_mutex_destroy(&stru->forks[i]);
	}
	pthread_mutex_destroy(&stru->lock);
	pthread_mutex_destroy(&stru->message);
	free(stru->philo);
	free(stru->forks);
	free(stru->thread);
}
