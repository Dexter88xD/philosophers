/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:52:38 by sohamdan          #+#    #+#             */
/*   Updated: 2025/03/23 05:18:37 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/***********HEADER FILES***********/

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

/***************MACROS***************/

# define USAGE_ERROR 1
# define LOGIC_ERROR 2
# define INT_ERROR 3
# define MALLOC_ERROR 4
# define THREAD_MUTEX_ERROR 5

# define NEED_JOIN 0
# define NO_NEED_JOIN 1

# define BEFORE_EATING 0
# define AFTER_EATING 1

# define TAKEN_A_FORK "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DIED "died"
# define FINISHED_EATING "finished eating!"

/***************STRUCTS***************/

typedef struct s_info
{
	int				nbr_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nbr_time_eat;
	long			start_clock;
	int				dead_philo;
	time_t			time;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
}					t_info;

typedef struct s_philo
{
	int				index;
	long			last_time_eat;
	t_info			*info;
	pthread_t		thread;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	*left_fork;
}					t_philo;

/***************PARSING AND CHECKING***************/

void				check_if_integer(char *input);

char				*ft_strchr(const char *s, int c);

int					check_initialise_input(char **av, t_info *input);
int					ft_atoi(const char *nptr);

void				check_death(t_philo *philo);

/***************INITALISING***************/

void				initialise_mutexes(t_info *info, t_philo *philo);
void				set_table(t_info *info, t_philo *philo);

long				current_time(void);

/***************SIMULATION***************/

void				one_philo_issue(t_info *info, t_philo *philo);

void				*simulate(void *param);

void				think_philosophers(t_philo *philo);

void				feed_philosophers(t_philo *philo);
void				feed_pair_philosophers(t_philo *philo);
void				feed_unpair_philosophers(t_philo *philo);

void				sleep_philosophers(t_philo *philo);

void				do_the_task(t_info *info, long timer);

/***************PRINTING***************/

void				print_messages(t_philo *philo, long time, char *message);

void				print_errors(int index);

/***************CLEANING AND FREEING***************/

void				cleanup(t_philo *philo, t_info *info);
void				clean_error_threads(t_info *info, t_philo *philo,
						int thread, int flag);

#endif
