/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:08:28 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/10/10 11:23:16 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_stru *stru(void)
{
    static t_stru  stru;
    
    return (&stru);
}

t_philo *philo(void)
{
    static t_philo philo;
    
    return (&philo);
}