/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:32:21 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/10/11 13:50:04 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <time.h>
# include <sys/time.h>

typedef struct	philo
{
	int	n;
	int	is_eat;
	int	is_sleep;
	int	is_die;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}								t_philo;

typedef struct	stru
{
	pthread_t	thread;
	int		nb_philo;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		nb_eat;
	unsigned long	start_time;
	t_philo	*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	
}								t_stru;


//							Estruturas Globais

t_stru	*stru(void);
t_philo *philo(void);

// 							Inicialização	

int ft_check_args(int argc, char **argv);
void	init_philo(void);
void	init_struct(int argc, char **argv);

//							Philosophers Table

int init_threads(void);
void*   routine(void *arg);
void	eat();

//							Utils

void	ft_bzero(void *dest, size_t n);
int	ft_atoi(const char *str);

#endif
