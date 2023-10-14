/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philopthread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:00:59 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/10/13 17:30:54 by dcarrilh         ###   ########.fr       */
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
		while (!philo->is_die)
		{
			eat(philo);
			menssage("is thinking", philo->n);
		}
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
			ft_usleep(1);
    }
    i = -1;
    while (++i <= stru()->nb_philo)
    {
      if (pthread_join(stru()->thread[i], NULL))
          return (1);
		}
    return (0);
}
