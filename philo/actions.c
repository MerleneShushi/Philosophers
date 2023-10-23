/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:59:09 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/10/22 17:12:22 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	menssage(char *str, t_philo *philo)
{
	unsigned long	time;

	pthread_mutex_lock(&philo->stru->message);
	time = get_time() - philo->stru->start_time;
	if (!philo->stru->died && ft_strcmp(str, "died") == 0)
	{
		printf("%lu %d %s\n", time, philo->n, str);
		philo->stru->died = 1;
	}
	else if (!philo->stru->died)
		printf("%lu %d %s\n", time, philo->n, str);
	pthread_mutex_unlock(&philo->stru->message);
}

void	take_fork(t_philo	*philo)
{
	if (philo->n % 2)
	{
		pthread_mutex_lock(philo->l_fork);
		menssage("has taken a fork", philo);
		pthread_mutex_lock(philo->r_fork);
		menssage("has taken a fork", philo);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		menssage("has taken a fork", philo);
		pthread_mutex_lock(philo->l_fork);
		menssage("has taken a fork", philo);
	}
}

int	eat(t_philo *philo)
{
	redmutex2(2, philo);
	if (philo->stru->died
		|| philo->stru->philo_eat_count == philo->stru->nb_philo)
	{
		pthread_mutex_unlock(&philo->stru->message);
		return (1);
	}
	redmutex2(3, philo);
	take_fork(philo);
	redmutex2(1, philo);
	philo->is_eat = 1;
	philo->eat_count++;
	redmutex2(4, philo);
	if (philo->eat_count == philo->stru->nb_eat)
		philo->stru->philo_eat_count++;
	redmutex(4, 0, philo);
	philo->t_philo_die = (get_time() - philo->stru->start_time)
		+ philo->stru->t_die;
	pthread_mutex_unlock(&philo->stru->lock);
	menssage("is eating", philo);
	usleep(philo->stru->t_eat * 1000);
	pthread_mutex_lock(&philo->stru->lock);
	philo->is_eat = 0;
	redmutex2(0, philo);
	return (0);
}

int	slepping(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_lock(&philo->stru->lock);
	pthread_mutex_lock(&philo->stru->message);
	if (philo->stru->died
		|| philo->stru->philo_eat_count == philo->stru->nb_philo)
	{
		pthread_mutex_unlock(&philo->stru->message);
		pthread_mutex_unlock(&philo->stru->lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->stru->message);
	pthread_mutex_unlock(&philo->stru->lock);
	menssage("is sleeping", philo);
	usleep(philo->stru->t_sleep * 1000);
	return (0);
}

int	thinking(t_philo *philo)
{
	if (((long)(philo->stru->t_die - philo->stru->t_sleep
			- philo->stru->t_eat) / 2) > 0)
		usleep((philo->stru->t_die - philo->stru->t_sleep
				- philo->stru->t_eat) / 2 * 1000);
	pthread_mutex_lock(&philo->stru->lock);
	pthread_mutex_lock(&philo->stru->message);
	if (philo->stru->died
		|| philo->stru->philo_eat_count == philo->stru->nb_philo)
	{
		pthread_mutex_unlock(&philo->stru->message);
		pthread_mutex_unlock(&philo->stru->lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->stru->message);
	pthread_mutex_unlock(&philo->stru->lock);
	menssage("is thinking", philo);
	return (0);
}
