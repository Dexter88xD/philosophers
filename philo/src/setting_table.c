/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:24:53 by sohamdan          #+#    #+#             */
/*   Updated: 2025/03/23 02:58:42 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void	do_the_task(t_info *info, long timer)
// {
// 	long	elapsed;
// 	long	start;

// 	elapsed = 0;
// 	start = current_time() - info->start_clock;
// 	while (elapsed < timer)
// 	{
// 		elapsed = (current_time() - info->start_clock) - start;
// 	}
// }

void	check_death(t_philo *philo)
{
	long	time;
	long	current;

	pthread_mutex_lock(&(philo->info->death_mutex));
	current = current_time() - philo->info->start_clock;
	time = current - philo->last_time_eat;
	if (time > philo->info->time_die)
	{
		print_messages(philo, current, DIED);
		// cleanup(philo, philo->info);
		exit(EXIT_SUCCESS);
		philo->info->dead_philo = 1;
	}
	pthread_mutex_unlock(&(philo->info->death_mutex));
}

void	*simulate(void *param)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)param;
	i = 0;
	while (1)
	{
		if (philo->info->nbr_time_eat != -1)
		{
			i++;
			if (i > philo->info->nbr_time_eat)
				break ;
		}
		think_philosophers(philo);
		check_death(philo);
		feed_philosophers(philo);
		sleep_philosophers(philo);
	}
	return (NULL);
}

void	set_table(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	info->start_clock = current_time();
	initialise_mutexes(info, philo);
	while (i < info->nbr_philo)
	{
		philo[i].index = i;
		philo[i].info = info;
		if (i + 1 < info->nbr_philo)
			philo[i].left_fork = &(philo[i + 1].right_fork);
		else
			philo[i].left_fork = &(philo[0].right_fork);
		if (pthread_create(&(philo[i].thread), NULL, simulate, &(philo[i])))
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
