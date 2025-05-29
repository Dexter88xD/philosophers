/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:28:26 by sohamdan          #+#    #+#             */
/*   Updated: 2025/04/22 18:49:56 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	feed_philosophers(t_philo *philo)
{
	int	check;

	if (!check_death(philo))
		return (0);
	if (philo->index % 2)
		check = feed_pair_philosophers(philo);
	else
		check = feed_unpair_philosophers(philo);
	if (check == 0)
		return (0);
	return (1);
}

int	feed_pair_philosophers(t_philo *philo)
{
	long	time;
	int		check;

	pthread_mutex_lock(&(philo->right_fork));
	if (!check_death(philo))
	{
		pthread_mutex_unlock(&(philo->right_fork));
		return (0);
	}
	time = current_time() - philo->info->start_clock;
	print_messages(philo, time, TAKEN_A_FORK);
	pthread_mutex_lock(philo->left_fork);
	if (!check_death(philo))
	{
		pthread_mutex_unlock(&(philo->right_fork));
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}
	time = current_time() - philo->info->start_clock;
	print_messages(philo, time, TAKEN_A_FORK);
	if (!check_death(philo))
	{
		pthread_mutex_unlock(&(philo->right_fork));
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}
	time = current_time() - philo->info->start_clock;
	print_messages(philo, time, EATING);
	philo->last_time_eat = current_time() - philo->info->start_clock;
	check = do_the_task(philo, philo->info->time_eat * 1000);
	pthread_mutex_unlock(&(philo->right_fork));
	pthread_mutex_unlock(philo->left_fork);
	if (check == 0)
		return (0);
	return (1);
}

int	feed_unpair_philosophers(t_philo *philo)
{
	long	time;
	int		check;

	pthread_mutex_lock(philo->left_fork);
	if (!check_death(philo))
	{
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}
	time = current_time() - philo->info->start_clock;
	print_messages(philo, time, TAKEN_A_FORK);
	pthread_mutex_lock(&(philo->right_fork));
	if (!check_death(philo))
	{
		pthread_mutex_unlock(&(philo->right_fork));
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}
	time = current_time() - philo->info->start_clock;
	print_messages(philo, time, TAKEN_A_FORK);
	if (!check_death(philo))
	{
		pthread_mutex_unlock(&(philo->right_fork));
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}
	time = current_time() - philo->info->start_clock;
	print_messages(philo, time, EATING);
	philo->last_time_eat = current_time() - philo->info ->start_clock;
	check = do_the_task(philo, philo->info->time_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(&(philo->right_fork));
	if (check == 0)
		return (0);
	return (1);
}

int	sleep_philosophers(t_philo *philo)
{
	long	time;
	int		check;

	if (!check_death(philo))
		return (0);
	time = current_time() - philo->info->start_clock;
	print_messages(philo, time, SLEEPING);
	check = do_the_task(philo, philo->info->time_sleep);
	if (check == 0)
		return (0);
	return (1);
}

int	think_philosophers(t_philo *philo)
{
	long	time;

	if (!check_death(philo))
		return (0);
	time = current_time() - philo->info->start_clock;
	print_messages(philo, time, THINKING);
	return (1);
}
