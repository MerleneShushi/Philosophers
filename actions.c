/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:59:09 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/10/20 17:38:20 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	menssage(char *str, t_philo *philo)
{
	unsigned long	time;

	pthread_mutex_lock(&stru()->message);
	time = get_time() - stru()->start_time;
	if (!stru()->died && ft_strcmp(str, "died") == 0)
	{
		printf("%lu %d %s\n", time, philo->n, str);
		stru()->died = 1;
	}
	else if (!stru()->died)
		printf("%lu %d %s\n", time, philo->n, str);
	pthread_mutex_unlock(&stru()->message);
}

void	take_fork(t_philo	*philo)
{
	pthread_mutex_lock(philo->l_fork);
	menssage("has taken a fork", philo);
	pthread_mutex_lock(philo->r_fork);
	menssage("has taken a fork", philo);
}

int	eat(t_philo *philo)
{
	pthread_mutex_lock(&stru()->lock);
	pthread_mutex_lock(&stru()->message);
	if (stru()->died || stru()->philo_eat_count == stru()->nb_philo)
	{
		pthread_mutex_unlock(&stru()->message);
		return (1);
	}
	pthread_mutex_unlock(&stru()->message);
	pthread_mutex_unlock(&stru()->lock);
	take_fork(philo);
	redmutex(1, philo->n - 1);
	philo->is_eat = 1;
	philo->eat_count++;
	pthread_mutex_unlock(&stru()->lock);
	pthread_mutex_lock(&stru()->lock);
	if (philo->eat_count == stru()->nb_eat)
		stru()->philo_eat_count++;
	pthread_mutex_unlock(&stru()->lock);
	pthread_mutex_lock(&stru()->lock);
	philo->t_philo_die = (get_time() - stru()->start_time) + stru()->t_die;
	pthread_mutex_unlock(&stru()->lock);
	menssage("is eating", philo);
	usleep(stru()->t_eat * 1000);
	pthread_mutex_lock(&stru()->lock);
	philo->is_eat = 0;
	redmutex(0, philo->n - 1);
	return (0);
}

int	slepping(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_lock(&stru()->lock);
	pthread_mutex_lock(&stru()->message);
	if (stru()->died || stru()->philo_eat_count == stru()->nb_philo)
	{
		pthread_mutex_unlock(&stru()->message);
		pthread_mutex_unlock(&stru()->lock);
		return (1);
	}
	pthread_mutex_unlock(&stru()->message);
	pthread_mutex_unlock(&stru()->lock);
	menssage("is sleeping", philo);
	usleep(stru()->t_sleep * 1000);
	return (0);
}

int	thinking(t_philo *philo)
{
	pthread_mutex_lock(&stru()->lock);
	pthread_mutex_lock(&stru()->message);
	if (stru()->died || stru()->philo_eat_count == stru()->nb_philo)
	{
		pthread_mutex_unlock(&stru()->message);
		pthread_mutex_unlock(&stru()->lock);
		return (1);
	}
	pthread_mutex_unlock(&stru()->message);
	pthread_mutex_unlock(&stru()->lock);
	menssage("is thinking", philo);
	return (0);
}
