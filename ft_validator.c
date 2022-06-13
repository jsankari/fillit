/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalmine <msalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 14:54:30 by msalmine          #+#    #+#             */
/*   Updated: 2020/08/29 14:33:11 by msalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_connect_check(char *s)
{
	int		n;

	n = 0;
	if (*(s + 1) != '#' && *(s - 1) != '#' && *(s + 5) != '#'
		&& *(s - 5) != '#')
		return (-1);
	if (*(s + 1) == '#')
		n++;
	if (*(s - 1) == '#')
		n++;
	if (*(s + 5) == '#')
		n++;
	if (*(s - 5) == '#')
		n++;
	return (n);
}

static int	ft_check_tetra(char *s)
{
	int		i;
	int		val;
	int		newl;
	int		con;

	i = 0;
	val = 0;
	newl = 0;
	con = 0;
	while (s[i] != '\0' && (s[i] == '#' || s[i] == '.' || s[i] == '\n'))
	{
		val += s[i];
		if (s[i] == '#')
			con += ft_connect_check(s + i);
		if (s[i] == '\n' && i % 5 == 4)
			newl++;
		i++;
	}
	if (val != 732 || i != 20 || newl != 4 || (con != 6 && con != 8))
		return (0);
	return (1);
}

int			ft_validator(int fd)
{
	int		ret;
	int		space;
	int		pieces;
	char	buf[21];

	space = 1;
	pieces = 0;
	while ((ret = read(fd, buf, 20)))
	{
		if (ret != 20)
			return (0);
		buf[ret] = '\0';
		if (!(ft_check_tetra(buf)))
			return (0);
		pieces++;
		if ((ret = read(fd, buf, 1)) == 0 || buf[0] != '\n')
			break ;
		space++;
	}
	close(fd);
	if (ret > 0)
		return (0);
	if (pieces > 26 || space != pieces)
		return (0);
	return (pieces);
}
