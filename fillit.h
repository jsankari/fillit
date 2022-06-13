/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalmine <msalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:06:18 by msalmine          #+#    #+#             */
/*   Updated: 2020/08/29 18:50:26 by msalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		main(int ac, char **av);
int		ft_validator(int fd);
int		**ft_coordinator(int fd, int pieces);
int		ft_grid_solver(int **coord, int pieces);

#endif
