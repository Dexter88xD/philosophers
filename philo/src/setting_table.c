/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:24:53 by sohamdan          #+#    #+#             */
/*   Updated: 2025/03/19 14:33:23 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	one_philo_issue(t_info *info, t_philo *philo)
{
	usleep(info->time_die);
	printf("%d %d died\n", info->time_die, philo->index);
	free(info);
	free(philo);
	exit(EXIT_SUCCESS);
}

void	set_table(t_info *info, t_philo *philo)
{
	int	i;
	
	initialise_mutexes(info, philo);
	i = 0;
	info->start_clock = current_time_info(info);
	while (i < info->nbr_philo)
	{
		philo[i].index = i;
		philo[i].info = info;
		if (i + 1 < info->nbr_philo)
			philo[i].left_fork = &(philo[i + 1].right_fork);
		else
			philo[i].left_fork = &(philo[0].right_fork);
		if (pthread_create(&(philo[i].thread), NULL, print_struct, &(philo[i])))
			clean_error_threads(info, philo, i, NEED_JOIN);
		i++;
	}
	i = 0;
	while (i < info->nbr_philo)
	{
		if (pthread_join(philo[i++].thread, NULL))
			clean_error_threads(info, philo, i, NO_NEED_JOIN);
	}
}
