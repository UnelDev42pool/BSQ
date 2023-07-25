/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edechena <edechena@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:11:04 by edechena          #+#    #+#             */
/*   Updated: 2023/07/25 12:01:45 by edechena         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

bool	ft_clear(t_data *d, unsigned short **matrix)
{
	if (d->map)
		free(d->map);
	if (matrix)
		free_matrix(matrix, d);
	return (true);
}

bool	solve(char *file)
{
	unsigned short	**matrix;
	t_data			d;

	init_data(&d);
	if (!file)
	{
		if (!read_stdin(&d))
			return (ft_clear(&d, NULL));
	}
	else
	{
		if (!read_file(&d, file))
			return (ft_clear(&d, NULL));
	}
	matrix = init_matrix(&d);
	if (!matrix)
		return (ft_clear(&d, NULL));
	if (!process(&d, matrix))
		return (ft_clear(&d, matrix));
	display_bsq(&d, matrix);
	ft_clear(&d, matrix);
	return (false);
}

int	main(int ac, char **av)
{
	int		i;

	if (ac > 1)
	{
		i = 1;
		while (i < ac)
			return (solve(av[i++]));
	}
	else
		return (solve(NULL));
}
