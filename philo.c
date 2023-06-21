/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:28:50 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/06/21 11:28:52 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
    t_philo	*philo;

    if (argc < 5 || argc > 6)
        return (ft_error("Wrong number of arguments\n"));
    philo = ft_init_philo(argv);
    if (!philo)
        return (ft_error("Malloc error\n"));
    if (ft_init_mutex(philo))
        return (ft_error("Mutex error\n"));
    if (ft_init_thread(philo))
        return (ft_error("Thread error\n"));
    ft_free_all(philo);
    return (0);
}
