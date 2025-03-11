/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:52:38 by sohamdan          #+#    #+#             */
/*   Updated: 2025/03/11 04:56:28 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define USAGE_ERROR 1
# define LOGIC_ERROR 2
# define INT_ERROR 3

# define NBR_OF_PHILOS 200
# define NBR_PHILO  0
# define TIME_DIE  1
# define TIME_EAT 2
# define TIME_SLEEP 3
# define NBR_TIME_EAT 4
# define END_OF_INPUT 5

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

/***********PARSING AND CHECKING***********/

char	*ft_strchr(const char *s, int c);
int		check_input(char **av, int *input);
int		ft_atoi(const char *nptr);

/***********PRINTING ERRORS***********/

void	print_usage_error(int index);

#endif
