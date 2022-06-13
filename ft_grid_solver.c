/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid_solver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalmine <msalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:50:30 by msalmine          #+#    #+#             */
/*   Updated: 2020/08/29 18:44:03 by msalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_fitcheck(char **grid, int *coord, int *pos)
{
	int		i;
	int		side;

	side = 0;
	while (grid[side])
		side++;
	i = 0;
	while (i <= 6)
	{
		if ((coord[i] + pos[0]) >= side || (coord[i + 1] + pos[1]) >= side ||
		(coord[i + 1] + pos[1]) < 0)
			return (0);
		if (grid[coord[i] + pos[0]][coord[i + 1] + pos[1]] != '.')
			return (0);
		i += 2;
	}
	return (1);
}

static void	ft_paint(char **grid, int *coord, char alpha, int *pos)
{
	if (grid[coord[0] + pos[0]][coord[1] + pos[1]] == alpha)
		alpha = '.';
	grid[coord[0] + pos[0]][coord[1] + pos[1]] = alpha;
	grid[coord[2] + pos[0]][coord[3] + pos[1]] = alpha;
	grid[coord[4] + pos[0]][coord[5] + pos[1]] = alpha;
	grid[coord[6] + pos[0]][coord[7] + pos[1]] = alpha;
}

static int	ft_backtrack(char **grid, int **coord, int side, char alpha)
{
	int		pos[2];

	alpha += 1;
	if (coord[alpha - 'A'] == NULL)
		return (1);
	pos[0] = 0;
	while (grid[pos[0]] != NULL)
	{
		pos[1] = 0;
		while (grid[pos[0]][pos[1]] != '\0')
		{
			if (ft_fitcheck(grid, coord[alpha - 'A'], pos))
			{
				ft_paint(grid, coord[alpha - 'A'], alpha, pos);
				if (ft_backtrack(grid, coord, side, alpha))
					return (1);
				else
					ft_paint(grid, coord[alpha - 'A'], alpha, pos);
			}
			pos[1] += 1;
		}
		pos[0] += 1;
	}
	alpha -= 1;
	return (0);
}

static char	**ft_make_grid(char **grid, int side)
{
	int		i;
	int		j;

	if (grid != NULL)
	{
		i = 0;
		while (grid[i] != NULL)
			free(grid[i++]);
		free(grid);
	}
	if (!(grid = (char **)malloc(sizeof(char*) * (side + 1))))
		return (NULL);
	grid[side] = NULL;
	i = 0;
	while (i < side)
	{
		if (!(grid[i] = (char *)malloc(sizeof(char) * (side + 1))))
			return (NULL);
		grid[i][side] = '\0';
		j = 0;
		while (j < side)
			grid[i][j++] = '.';
		i++;
	}
	return (grid);
}

int			ft_grid_solver(int **coord, int pieces)
{
	int		i;
	int		side;
	char	alpha;
	char	**grid;

	side = 0;
	while (side * side < (pieces * 4))
		side++;
	alpha = 'A' - 1;
	grid = NULL;
	grid = ft_make_grid(grid, side);
	while (!(ft_backtrack(grid, coord, side, alpha)))
		grid = ft_make_grid(grid, ++side);
	i = 0;
	while (grid[i] != NULL)
	{
		write(1, grid[i], side);
		write(1, "\n", 1);
		free(grid[i++]);
	}
	free(grid);
	return (0);
}
