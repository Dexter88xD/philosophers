/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:52:38 by sohamdan          #+#    #+#             */
/*   Updated: 2025/03/18 07:25:57 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/***********HEADER FILES***********/

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/***********MACROS***********/

# define USAGE_ERROR 1
# define LOGIC_ERROR 2
# define INT_ERROR 3
# define MALLOC_ERROR 4
# define THREAD_ERROR 5

# define NEED_JOIN 1
# define NO_NEED_JOIN 2

/***********STRUCTS***********/

typedef struct s_info
{
	int				nbr_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nbr_time_eat;
}					t_info;

typedef struct s_philo
{
	int				index;
	pthread_t		thread;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	t_info			*info;
}					t_philo;

/***********PARSING AND CHECKING***********/

void	check_if_integer(char *input);

char	*ft_strchr(const char *s, int c);

int		check_input(char **av, t_info *input);
int		ft_atoi(const char *nptr);

/***********INITALISING***********/

void	set_table(t_info *info, t_philo *philo);

/***********PRINTING ERRORS***********/

void	print_usage_error(int index);

/***********CLEANING AND FREEING***********/

void	clean_error_threads(t_info *info, t_philo *philo, int thread, int flag);

#endif
