/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:13:52 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/10/17 22:44:13 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	redmutex(int i, t_philo *philo)
{
	if (i == 1)
	{
		pthread_mutex_lock(&philo->lock);
		pthread_mutex_lock(&stru()->lock);
	}
	else
	{
		pthread_mutex_unlock(&stru()->lock);
		pthread_mutex_unlock(&philo->lock);
	}
}
