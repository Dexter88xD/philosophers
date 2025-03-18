/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:54:56 by sohamdan          #+#    #+#             */
/*   Updated: 2025/03/18 07:19:35 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*print_struct(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	printf("the philosophers number: %d\n", philo->index);
	return (NULL);
}

void	set_table(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->nbr_philo)
	{		
		if (pthread_create(&(philo[i].thread), NULL, print_struct, &(philo[i])))
			clean_error_threads(info, philo, i, NEED_JOIN);
		philo[i].index = i;
		philo[i].info = info;
		i++;
	}
	i = 0;
	while (i < info->nbr_philo)
	{
		if (pthread_join(philo[i].thread, NULL))
			clean_error_threads(info, philo, i, NO_NEED_JOIN);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_info	*info;
	t_philo	*philo;

	if (ac < 5 || ac > 6)
		return (print_usage_error(USAGE_ERROR), 1);
	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (print_usage_error(MALLOC_ERROR), 1);
	if (!check_input(av, info))
		return (free(info), 1);
	philo = (t_philo *)malloc(info->nbr_philo * sizeof(t_philo));
	if (!philo)
		return (print_usage_error(MALLOC_ERROR), 0);
	set_table(info, philo);
	free(info);
	free(philo);
	return (0);
}
