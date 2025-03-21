/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 07:18:24 by sohamdan          #+#    #+#             */
/*   Updated: 2025/03/21 14:45:25 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	clean_error_threads(t_info *info, t_philo *philo, int thread, int flag)
{
	int	i;

	i = 0;
	if (flag == NEED_JOIN)
	{
		while (i < thread)
		{
			pthread_join(philo[i].thread, NULL);
			pthread_mutex_destroy(&(philo[i].right_fork));
			i++;
		}
	}
	free(philo);
	free(info);
	print_errors(THREAD_MUTEX_ERROR);
	exit(EXIT_FAILURE);
}

void	cleanup(t_philo *philo, t_info *info)
{
	if (info)
		free(info);
	if (philo)
		free(philo);
}
