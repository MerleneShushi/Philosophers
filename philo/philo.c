/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:28:50 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/10/21 22:04:56 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_args(int argc, char **argv)
{
	int	i;
	int	j;

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

void	init_philo(t_stru *stru)
{
	int	i;

	i = -1;
	while (++i < stru->nb_philo)
	{
		stru->philo[i].stru = stru;
		stru->philo[i].n = i + 1;
		stru->philo[i].is_eat = 0;
		stru->philo[i].t_philo_die = stru->t_die;
		stru->philo[i].is_die = 0;
		stru->philo[i].eat_count = 0;
		pthread_mutex_init(&stru->philo[i].lock, NULL);
		stru->philo[i].l_fork = &stru->forks[i];
		stru->philo[i].r_fork = &stru->forks[(i + 1) % stru->nb_philo];
	}
}

void	init_struct(int argc, char **argv, t_stru *stru)
{
	int	i;

	i = -1;
	stru->nb_philo = ft_atoi(argv[1]);
	stru->t_die = (unsigned long)ft_atoi(argv[2]);
	stru->t_eat = (unsigned long)ft_atoi(argv[3]);
	stru->t_sleep = (unsigned long)ft_atoi(argv[4]);
	if (argc == 6)
		stru->nb_eat = ft_atoi(argv[5]);
	else
		stru->nb_eat = -1;
	stru->philo_eat_count = 0;
	stru->died = 0;
	stru->philo = malloc(sizeof(t_philo) * stru->nb_philo);
	stru->thread = malloc(sizeof(pthread_t) * stru->nb_philo);
	stru->forks = malloc(sizeof(pthread_mutex_t) * stru->nb_philo);
	while (++i < stru->nb_philo)
		pthread_mutex_init(&stru->forks[i], NULL);
	pthread_mutex_init(&stru->lock, NULL);
	pthread_mutex_init(&stru->message, NULL);
}

int	main(int argc, char **argv)
{
	t_stru		*stru;

	stru = malloc(sizeof(t_stru));
	if (argc < 5 || argc > 6)
		return (printf("Wrong number of arguments\n"));
	if (ft_check_args(argc, argv))
		return (printf("Wrong arguments\n"));
	if (atoi(argv[1]) < 1)
		return (printf("Miss Philosopher\n"));
	if (atoi(argv[2]) < 1 || atoi(argv[3]) < 1 || atoi(argv[4]) < 1)
		return (printf("Wrong Time\n"));
	init_struct(argc, argv, stru);
	init_philo(stru);
	init_threads(stru);
	free_destroy(stru);
	return (0);
}
