/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalmine <msalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 17:33:04 by msalmine          #+#    #+#             */
/*   Updated: 2020/08/29 18:36:11 by msalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	int		pieces;
	int		**coord;

	if (ac != 2)
	{
		write(1, "usage: ./fillit source_file\n", 28);
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) != -1)
	{
		if ((pieces = ft_validator(fd)))
		{
			if ((fd = open(av[1], O_RDONLY)) != -1)
			{
				if ((coord = ft_coordinator(fd, pieces)) != NULL)
				{
					ft_grid_solver(coord, pieces);
					return (0);
				}
			}
		}
	}
	write(1, "error\n", 6);
	return (0);
}
