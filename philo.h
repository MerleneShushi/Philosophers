/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:32:21 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/10/04 15:42:50 by dcarrilh         ###   ########.fr       */
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
	int	l_fork;
	int	r_fork;
	
	pthread_t	thread;
}								t_philo;

typedef struct	stru
{
	int		nb_philo;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		nb_eat;
	t_philo	*philo;
	
}								t_stru;


t_stru	*stru(void);

int ft_check_args(int argc, char **argv);
int	ft_atoi(const char *str);
int	init_philo();
void*   routine();

#endif
