/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:28:26 by sohamdan          #+#    #+#             */
/*   Updated: 2025/03/19 14:44:36 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	current_time_info(t_info *info)
{
	long	time;
	
	gettimeofday(&(info->clock), NULL);
	time = info->clock.tv_sec * 1000;
	time += info->clock.tv_usec / 1000;
	return (time);
}

long	current_time(t_philo *philo)
{
	long	time;
	
	gettimeofday(&(philo->info->clock), NULL);
	time = philo->info->clock.tv_sec * 1000;
	time += philo->info->clock.tv_usec / 1000;
	return (time);
}

void	*print_struct(void *param)
{
	t_philo	*philo;
	int	i = 0;
	
	philo = (t_philo *)param;
	while (i < philo->info->nbr_time_eat)
	{
		pthread_mutex_lock(&(philo->info->keep_order));
		if (philo->index % 2)
		{
			pthread_mutex_lock(&(philo->right_fork));
			philo->info->time = current_time(philo) - philo->info->start_clock;
			printf("%ld %d has taken a fork\n", philo->info->time, philo->index);
			pthread_mutex_lock(philo->left_fork);
			philo->info->time = current_time(philo) - philo->info->start_clock;
			printf("%ld %d has taken a fork\n", philo->info->time,  philo->index);
			philo->info->time = current_time(philo) - philo->info->start_clock;
			printf("%ld %d is eating\n", philo->info->time,  philo->index);
			usleep(philo->info->time_eat * 1000);
			pthread_mutex_unlock(&(philo->right_fork));
			pthread_mutex_unlock(philo->left_fork);
		}
		else
		{
			pthread_mutex_lock(philo->left_fork);
			printf("%ld %d has taken a fork\n", philo->info->time, philo->index);
			philo->info->time = current_time(philo) - philo->info->start_clock;
			pthread_mutex_lock(&(philo->right_fork));
			printf("%ld %d has taken a fork\n", philo->info->time, philo->index);
			philo->info->time = current_time(philo) - philo->info->start_clock;
			printf("%ld %d is eating\n", philo->info->time,  philo->index);
			usleep(philo->info->time_eat * 1000);
			pthread_mutex_unlock(philo->left_fork);
			pthread_mutex_unlock(&(philo->right_fork));
		}
		pthread_mutex_unlock(&(philo->info->keep_order));
		philo->info->time = current_time(philo) - philo->info->start_clock;
		printf("%ld %d is sleeping\n", philo->info->time, philo->index);
		usleep(philo->info->time_sleep * 1000);
		philo->info->time = current_time(philo) - philo->info->start_clock;
		printf("%ld %d is thinking\n", philo->info->time, philo->index);
		i++;
	}
	return (NULL);
}

