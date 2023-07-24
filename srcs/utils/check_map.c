/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edechena <edechena@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:10:45 by edechena          #+#    #+#             */
/*   Updated: 2023/07/24 10:10:47 by edechena         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bsq.h"

bool	check_map2(t_data *d, int n)
{
	int	i;

	i = 0;
	d->nbr_lines = 0;
	while (i < n)
	{
		if (d->map[i] > '9' || d->map[i] < '0')
		{
			ft_putstr("map error\n");
			return (false);
		}
		d->nbr_lines = d->nbr_lines * 10 + d->map[i++] - '0';
	}
	return (true);
}

bool	check_map(t_data *d)
{
	unsigned int	i;

	i = 0;
	while (d->map[i] && d->map[i] != '\n')
		i++;
	if (!d->map[i] || !d->map[i + 1])
	{
		ft_putstr("map error\n");
		return (false);
	}
	d->n = i + 1;
	d->filler = d->map[--i];
	d->obstacle = d->map[--i];
	d->empty = d->map[--i];
	if (d->empty == d->filler || d->empty == d->obstacle
		|| d->filler == d->obstacle)
	{
		ft_putstr("map error\n");
		return (false);
	}
	return (check_map2(d, i));
}

bool	read_len_lines(t_data *d)
{
	unsigned int	i;

	if (d->nbr_lines == 0)
	{
		ft_putstr("map error\n");
		return (false);
	}
	i = d->n;
	while (d->map[i] && d->map[i] != '\n')
		i++;
	d->len_lines = i - d->n;
	if (d->len_lines == 0)
	{
		ft_putstr("map error\n");
		return (false);
	}
	return (true);
}
