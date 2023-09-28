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

int ft_isdigit(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    while (i < argc)
    {
        j = 0;
        while (argv[i][j])
        {
            if (argv[i][j] < '0' || argv[i][j] > '9')
                return (-1);
            j++;
        }
        i++;
    }
    return (0);
}

int	main(int argc, char **argv)
{
    t_philo	*philo;

    if (argc < 5 || argc > 6)
        return (printf("Wrong number of arguments\n"));
    if (ft_check_args(argc, argv) == -1)
        return (printf("Wrong arguments\n"));
    philo = ft_init_philo(argv);
    return (0);
}
