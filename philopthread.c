/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philopthread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:00:59 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/10/06 15:33:11 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	b = 0;
	c = 1;
	while (str[a] != '\0')
	{
		while ((str[a] == 32) || (str[a] > 8 && str[a] < 14))
			a++;
		if (str[a] == 45 || str[a] == 43)
		{
			if (str[a] == 45)
				c = -c;
			a++;
		}
		while (str[a] > 47 && str[a] < 58)
			b = b * 10 + str[a++] - 48;
		return (b * c);
	}
	return (0);
}

void*   routine()
{
    while (!stru()->philo->is_die)
		{
			if (stru()->philo->is_eat)
				eat();
		}
		return (NULL);
}

void	eat()
{
	pthread_mutex_lock(&stru()->mutex_fork);
	printf("timestamp_in_ms %d has taken a fork\n", stru()->philo->n);
	printf("timestamp_in_ms %d has taken a fork\n", stru()->philo->n);
	printf("timestamp_in_ms %d is eat\n", stru()->philo->n);
	sleep(10);
	pthread_mutex_unlock(&stru()->mutex_fork);
}

int init_philo(void)
{
    int i = 0;
    
		
    while (++i <= stru()->nb_philo)
    {
        stru()->philo[i].n = i;
				if (pthread_create(&stru()->philo[i].thread, NULL, &routine, NULL))
            return (printf("ERROR CREATE PTHREAD"));
        printf("Pthread %d init\n", i);
    }
    i = 0;
    while (++i <= stru()->nb_philo)
    {
        if (pthread_join(stru()->philo[i].thread, NULL))
            return (1);
        printf("Pthread %d close\n", i);
    }
    return (0);
}
