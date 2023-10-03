/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:28:50 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/10/03 12:12:19 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_bzero(void *dest, size_t n)
{
	unsigned char	*str;
	size_t			a;

	a = 0;
	str = (unsigned char *)dest;
	while (a < n)
	{
		str[a] = '\0';
		a++;
	}
}

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

int	main(int argc, char **argv)
{
		
		ft_bzero(philo(), sizeof(t_philo));
		if (argc < 5 || argc > 6)
				return (printf("Wrong number of arguments\n"));
		if (ft_check_args(argc, argv))
				return (printf("Wrong arguments\n"));
		else
		init_philo(argv);
		return (0);
}
