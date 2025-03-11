/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:54:56 by sohamdan          #+#    #+#             */
/*   Updated: 2025/03/11 04:56:44 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_if_integer(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] < '0' || input[i] > '9')
		{
			print_usage_error(INT_ERROR);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int	check_input(char **av, int *input)
{
	int	i;
	int	j;
	int	temp;
	int	temp_array[5];

	i = 0;
	j = 0;
	while (av[++i])
	{
		check_if_integer(av[i]);
		temp = ft_atoi(av[i]);
		if (temp <= 0)
			(print_usage_error(LOGIC_ERROR), exit(EXIT_FAILURE));
		temp_array[j++] = temp;
	}
	input[NBR_PHILO] = temp_array[0];
	input[TIME_DIE] = temp_array[1];
	input[TIME_EAT] = temp_array[2];
	input[TIME_SLEEP] = temp_array[3];
	if (j == 4)
		temp_array[j] = 0;
	else
		input[END_OF_INPUT] = 0;
	input[NBR_TIME_EAT] = temp_array[4];
	return (1);
}

int	main(int ac, char **av)
{
	int	i;
	int	input[5];

	if (ac < 5 || ac > 6)
	{
		print_usage_error(USAGE_ERROR);
		return (1);
	}
	if (!check_input(av, input))
		return (1);
	i = 0;
	while (input[i])
	{
		printf("Argument: %d\n", input[i]);
		i++;
	}
	return (0);
}
