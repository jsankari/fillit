/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coordinator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalmine <msalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 11:44:00 by jsankari          #+#    #+#             */
/*   Updated: 2020/08/29 17:01:38 by msalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*ft_one_tetro(char *buf)
{
	int		i;
	char	*tetro;

	if (!(tetro = (char *)malloc(sizeof(char) * 21)))
		return (NULL);
	i = 0;
	while (i < 20)
	{
		tetro[i] = buf[i];
		i++;
	}
	tetro[i] = '\0';
	return (tetro);
}

static char	**ft_read_file(int fd, int pieces)
{
	int		i;
	int		ret;
	char	buf[21];
	char	**tetro;

	i = 0;
	if (!(tetro = (char **)malloc(sizeof(char *) * pieces)))
		return (NULL);
	while ((ret = read(fd, buf, 21)))
	{
		if (!(tetro[i] = ft_one_tetro(buf)))
		{
			while (i >= 0)
				free(tetro[i]);
			free(tetro);
			return (NULL);
		}
		i++;
	}
	close(fd);
	return (tetro);
}

static void	ft_convert_coord(char *tet, int *ray)
{
	int i;
	int refy;
	int refx;
	int n;

	i = 0;
	n = 0;
	while (tet[i] != '\0')
	{
		if (tet[i] == '#')
		{
			if (n == 0)
			{
				refx = i % 5;
				refy = i / 5;
			}
			ray[n] = i / 5 - refy;
			ray[n + 1] = (i % 5) - refx;
			n += 2;
		}
		i++;
	}
}

static void	ft_free_array(int **array, int i)
{
	int		j;

	j = 0;
	while (j <= i)
		free(array[j++]);
	free(array);
}

int			**ft_coordinator(int fd, int pieces)
{
	int		i;
	char	**tetro;
	int		**coord;

	i = 0;
	if (!(tetro = ft_read_file(fd, pieces)))
		return (NULL);
	if (!(coord = (int **)malloc(sizeof(int *) * (pieces + 1))))
		return (NULL);
	while (i < pieces)
	{
		if (!(coord[i] = (int *)malloc(sizeof(int) * 8)))
		{
			ft_free_array(coord, i);
			return (NULL);
		}
		ft_convert_coord(tetro[i], coord[i]);
		i++;
	}
	coord[i] = NULL;
	i = 0;
	while (i < pieces)
		free(tetro[i++]);
	free(tetro);
	return (coord);
}
