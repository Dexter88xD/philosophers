/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:34:12 by sohamdan          #+#    #+#             */
/*   Updated: 2025/03/21 12:37:42 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	current_time(void)
{
	long			time;
	struct timeval	clock;

	gettimeofday(&clock, NULL);
	time = clock.tv_sec * 1000;
	time += clock.tv_usec / 1000;
	return (time);
}

void	check_if_integer(char *input)
{
	int	i;

	i = 0;
	if (input[0] == '-' || input[0] == '\0')
	{
		print_errors(INT_ERROR);
		exit(EXIT_FAILURE);
	}
	while (input[i])
	{
		if (input[i] < '0' || input[i] > '9')
		{
			print_errors(INT_ERROR);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

int	check_initialise_input(char **av, t_info *info)
{
	int	i;

	i = 0;
	while (av[++i])
		check_if_integer(av[i]);
	info->nbr_philo = ft_atoi(av[1]);
	info->time_die = ft_atoi(av[2]);
	info->time_eat = ft_atoi(av[3]);
	info->time_sleep = ft_atoi(av[4]);
	if (info->nbr_philo == 0 || info->time_die == 0)
		return (print_errors(LOGIC_ERROR), 0);
	if (info->time_eat == 0 || info->time_sleep == 0)
		return (print_errors(LOGIC_ERROR), 0);
	if (i == 5)
		info->nbr_time_eat = -1;
	else
	{
		info->nbr_time_eat = ft_atoi(av[5]);
		if (info->nbr_time_eat == 0)
			return (print_errors(LOGIC_ERROR), 0);
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sym;

	i = 0;
	sym = 1;
	while ((*nptr > 8 && *nptr < 14) || *nptr == 32)
		nptr++;
	if (*nptr == '-')
	{
		nptr++;
		sym = -sym;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr > 47 && *nptr < 58)
	{
		i = (*nptr - 48) + i * 10;
		nptr++;
	}
	return (i * sym);
}
