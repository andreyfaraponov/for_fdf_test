/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_from_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:05:39 by afarapon          #+#    #+#             */
/*   Updated: 2018/01/09 15:18:33 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		get_line_to_arr(char *line, t_mlx *mlx, int y)
{
	int		x;
	char	**spl;
	int		i;

	i = 0;
	x = 0;
	spl = ft_strsplit(line, ' ');
	mlx->points[y] = (int*)malloc(sizeof(int) * mlx->x_pts_size);
	while (x < mlx->x_pts_size)
	{
		mlx->points[y][x] = ft_atoi(spl[x]);
		x++;
	}
	while (spl[i])
		free(spl[i++]);
	free(spl);
}


void			ft_get_pts_array(char *fname, t_mlx *mlx)
{
	int		file;
	int		y;
	char	*line;

	file = open(fname, O_RDONLY);
	mlx->points = (int**)malloc(sizeof(int*) * mlx->y_pts_size);
	y = 0;
	while (y < mlx->y_pts_size && get_next_line(file, &line))
	{
		get_line_to_arr(line, mlx, y);
		free(line);
		y++;
	}
}
