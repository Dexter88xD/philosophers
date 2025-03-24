/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:54:56 by sohamdan          #+#    #+#             */
/*   Updated: 2025/03/24 11:26:46 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	initialise_mutexes(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&(info->print_mutex), NULL))
		clean_error_threads(info, philo, i, NO_NEED_JOIN);
	if (pthread_mutex_init(&(info->death_mutex), NULL))
		clean_error_threads(info, philo, i, NO_NEED_JOIN);
	while (i < info->nbr_philo)
	{
		if (pthread_mutex_init(&(philo[i++].right_fork), NULL))
			clean_error_threads(info, philo, i, NO_NEED_JOIN);
		i++;
	}
}

void	one_philo_issue(t_info *info, t_philo *philo)
{
	printf("%d %d is thinking\n", 0, philo->index);
	usleep(info->time_die);
	printf("%d %d died\n", info->time_die, philo->index);
	free(info);
	free(philo);
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_info	*info;
	t_philo	*philo;
	int		i;

	if (ac < 5 || ac > 6)
		return (print_errors(USAGE_ERROR), 1);
	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (print_errors(MALLOC_ERROR), 1);
	memset(info, 0, sizeof(t_info));
	if (!check_initialise_input(av, info))
		return (free(info), 1);
	philo = (t_philo *)malloc(info->nbr_philo * sizeof(t_philo));
	if (!philo)
		return (free(info), print_errors(MALLOC_ERROR), 1);
	i = 0;
	while (i < info->nbr_philo)
		memset(&philo[i++], 0, sizeof(t_philo));
	if (info->nbr_philo == 1)
		one_philo_issue(info, philo);
	set_table(info, philo);
	cleanup(philo, info);
	return (0);
}
