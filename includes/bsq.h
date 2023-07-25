/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edechena <edechena@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:11:10 by edechena          #+#    #+#             */
/*   Updated: 2023/07/25 15:48:38 by edechena         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1000000
# endif

# define BUFFER_INIT	4096
# define BUFFER_STDIN	280000

typedef struct s_data
{
	int		bsq_x;
	int		bsq_y;
	char	empty;
	int		fd;
	char	filler;
	int		len_lines;
	char	*map;
	long	n;
	int		nbr_lines;
	char	obstacle;
}	t_data;

bool			check_map(t_data *d);
bool			read_len_lines(t_data *d);

void			free_matrix(unsigned short **matrix, t_data *d);
unsigned short	**free_matrix_i(unsigned short **matrix, int i);

void			ft_putstr(char *str);

char			*ft_strjoin_bsq(char *s1, const int size1,
					char *s2, const int size2);

void			init_data(t_data *d);
unsigned short	**init_matrix(t_data *d);

void			display_bsq(t_data *d, unsigned short **matrix);

bool			process(t_data *d, unsigned short **matrix);

bool			read_file(t_data *d, char *file);
bool			read_stdin(t_data *d);

#endif
