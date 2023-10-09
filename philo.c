/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:28:50 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/10/09 17:30:40 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_check_args(int argc, char **argv)
{
		int i;
		int j;

		i = 0;
		while (++i < argc)
		{
				j = -1;
				while (argv[i][++j])
				{
						if (argv[i][j] < '0' || argv[i][j] > '9')
								return (1);
				}
		}
		return (0);
}

void	init_struct(int argc, char **argv)
{
	int	i;
	
	i = 0;
	ft_bzero(stru(), sizeof(t_stru));
	stru()->nb_philo = ft_atoi(argv[1]);
	stru()->t_die = ft_atoi(argv[2]);
	stru()->t_eat = ft_atoi(argv[3]);
	stru()->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		stru()->nb_eat = ft_atoi(argv[5]);
	stru()->philo = malloc(sizeof(t_philo) * stru()->nb_philo);
	ft_bzero(stru()->philo, sizeof(t_philo));
	stru()->fork = malloc(sizeof(pthread_mutex_t) * stru()->nb_philo);
	pthread_mutex_init(&stru()->fork[0], NULL);
	stru()->philo[0].n = 1;
	stru()->philo[0].l_fork = &stru()->fork[stru()->nb_philo - 1];
	stru()->philo[0].r_fork = &stru()->fork[0];
	pthread_mutex_destroy(&stru()->fork[0]);
	while (++i < stru()->nb_philo)
	{
		pthread_mutex_init(&stru()->fork[i], NULL);
		stru()->philo[i].n = i + 1;
		stru()->philo[i].l_fork = &stru()->fork[i - 1];
		stru()->philo[i].r_fork = &stru()->fork[i];
		pthread_mutex_destroy(&stru()->fork[i]);
	}
}

int	main(int argc, char **argv)
{
		pthread_mutex_init(&stru()->lock, NULL);
		
		if (argc < 5 || argc > 6)
				return (printf("Wrong number of arguments\n"));
		if (ft_check_args(argc, argv))
				return (printf("Wrong arguments\n"));
		init_struct(argc, argv);
		init_philo();
		pthread_mutex_destroy(&stru()->lock);
		return (0);
}
