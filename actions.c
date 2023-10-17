/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:59:09 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/10/17 19:44:01 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void menssage(char *str, t_philo *philo)
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

void	free_fork(t_philo *philo)
{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
}

int	eat(t_philo *philo)
{
	pthread_mutex_lock(&stru()->message);
	if (stru()->died || stru()->philo_eat_count == stru()->nb_philo)
	{
		pthread_mutex_unlock(&stru()->message);
		return (1);
	}
	pthread_mutex_unlock(&stru()->message);
	take_fork(philo);
	pthread_mutex_lock(&philo->lock);
	pthread_mutex_lock(&stru()->lock);
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
	pthread_mutex_unlock(&stru()->lock);
	pthread_mutex_unlock(&philo->lock);
	free_fork(philo);
	return (0);
}

int	slepping(t_philo *philo)
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
