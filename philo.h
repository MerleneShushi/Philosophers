/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:32:21 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/10/09 17:32:09 by dcarrilh         ###   ########.fr       */
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
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	int	is_eat;
	int	is_sleep;
	int	is_thinking;
	int	n;
	int	is_die;
}								t_philo;

typedef struct	stru
{
	pthread_t	thread;
	int		nb_philo;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		nb_eat;
	t_philo	*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	lock;
	
}								t_stru;


t_stru	*stru(void);

int ft_check_args(int argc, char **argv);
int	ft_atoi(const char *str);
int	init_philo();
void*   routine();
void	eat();
void	ft_bzero(void *dest, size_t n);

#endif
