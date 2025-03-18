/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:52:15 by sohamdan          #+#    #+#             */
/*   Updated: 2025/03/18 10:46:51 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_usage_error(int index)
{
	if (index == USAGE_ERROR)
	{
		write(2, "Usage: ./philo number_of_philosophers time_to_die", 49);
		write(2, " time_to_eat time_to_sleep ", 27);
		write(2, "[number_of_times_each_philosopher_must_eat]\n", 44);
	}
	else if (index == LOGIC_ERROR)
	{
		write(2, "Error\n", 6);
		write(2, "Please provide a valid input \n", 29);
		write(2, "(more than one philosopher and enough time)\n", 45);
	}
	else if (index == INT_ERROR)
	{
		write(2, "Error\n", 6);
		write(2, "Please provide a valid input (positive numbers)\n", 48);
	}
	else if (index == MALLOC_ERROR)
		write(2, "Error\nAllocation failed\n", 24);
	else if (index == THREAD_MUTEX_ERROR)
		write(2, "Error\nThread or mutex creation failed\n", 38);
}
