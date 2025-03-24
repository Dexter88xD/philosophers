/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:28:26 by sohamdan          #+#    #+#             */
/*   Updated: 2025/03/24 01:18:48 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	feed_philosophers(t_philo *philo)
{
	if (philo->index % 2)
		feed_pair_philosophers(philo);
	else
		feed_unpair_philosophers(philo);
}

void	feed_pair_philosophers(t_philo *philo)
{
	long	time;

	pthread_mutex_lock(&(philo->right_fork));
	time = current_time() - philo->info->start_clock;
	print_messages(philo, time, TAKEN_A_FORK);
	pthread_mutex_lock(philo->left_fork);
	time = current_time() - philo->info->start_clock;
	print_messages(philo, time, TAKEN_A_FORK);
	time = current_time() - philo->info->start_clock;
	print_messages(philo, time, EATING);
	philo->last_time_eat = current_time() - philo->info->start_clock;
	do_the_task(philo->info, philo->info->time_eat);
	pthread_mutex_unlock(&(philo->right_fork));
	pthread_mutex_unlock(philo->left_fork);
}

void	feed_unpair_philosophers(t_philo *philo)
{
	long	time;

	pthread_mutex_lock(philo->left_fork);
	time = current_time() - philo->info->start_clock;
	print_messages(philo, time, TAKEN_A_FORK);
	pthread_mutex_lock(&(philo->right_fork));
	time = current_time() - philo->info->start_clock;
	print_messages(philo, time, TAKEN_A_FORK);
	time = current_time() - philo->info->start_clock;
	print_messages(philo, time, EATING);
	philo->last_time_eat = current_time() - philo->info ->start_clock;
	do_the_task(philo->info, philo->info->time_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(&(philo->right_fork));
}

void	sleep_philosophers(t_philo *philo)
{
	long	time;

	time = current_time() - philo->info->start_clock;
	print_messages(philo, time, SLEEPING);
	do_the_task(philo->info, philo->info->time_sleep);
}

void	think_philosophers(t_philo *philo)
{
	long	time;

	time = current_time() - philo->info->start_clock;
	print_messages(philo, time, THINKING);
}
