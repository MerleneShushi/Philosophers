/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:30:07 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/10/17 22:36:14 by dcarrilh         ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	b = 0;
	c = 1;
	while (str[a] != '\0')
	{
		while ((str[a] == 32) || (str[a] > 8 && str[a] < 14))
			a++;
		if (str[a] == 45 || str[a] == 43)
		{
			if (str[a] == 45)
				c = -c;
			a++;
		}
		while (str[a] > 47 && str[a] < 58)
			b = b * 10 + str[a++] - 48;
		return (b * c);
	}
	return (0);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	if (str2[i] != '\0')
		return (1);
	return (0);
}
