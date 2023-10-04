/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philopthread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:00:59 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/10/04 15:44:15 by dcarrilh         ###   ########.fr       */
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

int x = 0;

void*   routine()
{
    if 
}

int init_philo(void)
{
    int i = 0;
    

    while (++i <= stru()->nb_philo)
    {
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
    printf("Number of x: %d\n", x);
    return (0);
}
