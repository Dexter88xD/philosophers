/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:54:56 by sohamdan          #+#    #+#             */
/*   Updated: 2025/03/19 10:26:03 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_info	*info;
	t_philo	*philo;
	int		i;

	if (ac < 5 || ac > 6)
		return (print_usage_error(USAGE_ERROR), 1);
	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (print_usage_error(MALLOC_ERROR), 1);
	memset(info, 0, sizeof(t_info));
	if (!check_initialise_input(av, info))
		return (free(info), 1);
	pthread_mutex_init(&(info->keep_order), NULL);
	philo = (t_philo *)malloc(info->nbr_philo * sizeof(t_philo));
	if (!philo)
		return (free(info), print_usage_error(MALLOC_ERROR), 1);
	i = 0;
	while (i < info->nbr_philo)
		memset(&philo[i++], 0, sizeof(t_philo));
	if (info->nbr_philo == 1)
		one_philo_issue(info, philo);
	set_table(info, philo);
	cleanup(philo, info);
	return (0);
}
