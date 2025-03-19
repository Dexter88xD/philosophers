/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialising.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:27:26 by sohamdan          #+#    #+#             */
/*   Updated: 2025/03/18 22:27:59 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	initialise_mutexes(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->nbr_philo)
	{
		if (pthread_mutex_init(&(philo[i++].right_fork), NULL))
			clean_error_threads(info, philo, i, NEED_JOIN);
		i++;
	}
}
