/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:32:21 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/10/20 16:55:57 by dcarrilh         ###   ########.fr       */
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

typedef struct philo
{
	int							n;
	int							is_eat;
	unsigned long				t_philo_die;
	int							is_die;
	int							eat_count;
	pthread_mutex_t				lock;
	pthread_mutex_t				*l_fork;
	pthread_mutex_t				*r_fork;
}									t_philo;

typedef struct stru
{
	int							nb_philo;
	unsigned long				t_die;
	unsigned long				t_eat;
	unsigned long				t_sleep;
	int							nb_eat;
	int							philo_eat_count;
	int							died;
	unsigned long				start_time;
	t_philo						*philo;
	pthread_t					control;
	pthread_t					*thread;
	pthread_mutex_t				*forks;
	pthread_mutex_t				lock;
	pthread_mutex_t				message;
}									t_stru;

//							Estruturas Globais

t_stru					*stru(void);
t_philo					*philo(void);

// 							Inicialização	

int						ft_check_args(int argc, char **argv);
void					init_philo(void);
void					init_struct(int argc, char **argv);

//							Threads

int						init_threads(void);
unsigned long			get_time(void);

//							Philosophers Table

void					*routine(void *arg);
void					*control_routine(void *arg);
int						eat(t_philo *philo);
int						slepping(t_philo *philo);
int						thinking(t_philo *philo);
void					take_fork(t_philo	*philo);
void					free_fork(t_philo *philo);
void					menssage(char *str, t_philo	*philo);
void					redmutex(int i, int p);

//							Utils

void					ft_bzero(void *dest, size_t n);
int						ft_atoi(const char *str);
int						ft_strcmp(char *str1, char *str2);

#endif
