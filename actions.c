/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:59:09 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/10/13 17:32:21 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void menssage(char *str, int n)
{
    unsigned long	time;
    
		pthread_mutex_lock(&stru()->message);
		time = get_time() - stru()->start_time;
    printf("%lu %d %s\n", time, n, str);
    pthread_mutex_unlock(&stru()->message);
}
  
void	take_fork(t_philo	*philo)
{
		pthread_mutex_lock(philo->l_fork);
		menssage("has taken a fork", philo->n);
		pthread_mutex_lock(philo->r_fork);
		menssage("has taken a fork", philo->n);
}

void	free_fork(t_philo *philo)
{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		menssage("is sleeping", philo->n);
		usleep(stru()->t_sleep * 1000);
}

void	eat(t_philo *philo)
{
	take_fork(philo);
	pthread_mutex_lock(&philo->lock);
	pthread_mutex_lock(&stru()->lock);
	if (get_time() > (unsigned long)philo->t_philo_die)
	{
		menssage("died", philo->n);
		pthread_mutex_unlock(&stru()->lock);
		pthread_mutex_unlock(&philo->lock);
		return ;
	}
	stru()->philo->is_eat = 1;
	pthread_mutex_unlock(&stru()->lock);
	pthread_mutex_lock(&stru()->lock);
	philo->t_philo_die = get_time() + stru()->t_die;
	pthread_mutex_unlock(&stru()->lock);
	menssage("is eating", philo->n);
	usleep(stru()->t_eat * 1000);
	pthread_mutex_lock(&stru()->lock);
	stru()->philo->is_eat = 0;
	pthread_mutex_unlock(&stru()->lock);
	pthread_mutex_unlock(&philo->lock);
	free_fork(philo);
}
