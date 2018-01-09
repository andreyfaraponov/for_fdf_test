/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:32:35 by afarapon          #+#    #+#             */
/*   Updated: 2018/01/09 15:54:54 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_key_handle_mlx(int key, void *mlx)
{
	if (key == 53)
		ft_exit((t_mlx*)mlx);
	else if (key == LEFT)
		ft_left((t_mlx*)mlx);
	else if (key == RIGHT)
		ft_right((t_mlx*)mlx);
	else if (key == DOWN)
		ft_down((t_mlx*)mlx);
	else if (key == UP)
		ft_up((t_mlx*)mlx);
	return (0);
}

int			exit_cross(void)
{
	exit(1);
}

void		ft_canvas_usage(t_mlx *mlx)
{
	mlx_string_put(mlx->init, mlx->window, 20, 15, 0x0FFF0000, "Move left:  arrow left");
	mlx_string_put(mlx->init, mlx->window, 20, 30, 0x00FF0000, "Move right: arrow right");
	mlx_string_put(mlx->init, mlx->window, 20, 45, 0x00FFFF, "Move down:  arrow down");
	mlx_string_put(mlx->init, mlx->window, 20, 60, 0xFF00FF, "Move up:    arrow up");
	ft_printf("Init usage\n");
}

t_point prepare_point(t_point raw_p, t_mlx *mlx)
{
	t_point ret;

	ret.x = raw_p.x - (mlx->x_pts_size - 1)/2.0;
	ret.y = raw_p.y - (mlx->y_pts_size - 1)/2.0; 
	ret.z = raw_p.z / 2.0;
 // ret = view_rotate(ret, mlx->view);

	ret.color = raw_p.color;
	ret.x *= 25;
	ret.y *= 25;
	ret.x += mlx->x_offset;
	ret.y += mlx->y_offset;
	return (ret);
}

void		ft_run_mlx(t_mlx *mlx)
{
	int			x;
	int			y;
	t_point		point;

	y = 0;
	ft_window_init(mlx);
	ft_canvas_usage(mlx);
	mlx->x_offset = W_X_SIZE / 2;
	mlx->y_offset = W_Y_SIZE / 2;
	// mlx_hook(mlx->window, 2, 5, &ft_key_handle_mlx, mlx);
	// mlx_hook(mlx->window, 17, 1L << 17, &exit_cross, mlx);
	while (y < mlx->y_pts_size)
	{
		x = 0;
		while (x < mlx->x_pts_size)
		{
			point.x = x;
			point.y = y;
			point.z = mlx->points[y][x];
			point.color = 0xFFFFFF;
			point = prepare_point(point, mlx);
			mlx_pixel_put(mlx->init, mlx->window, point.x, point.y, point.color);
			x++;
		}
		y++;
	}
	mlx_key_hook(mlx->window, ft_key_handle_mlx, mlx);
	mlx_loop(mlx->init);
}

int			main(int ac, char **av)
{
	t_mlx	mlx;

	ft_memset(&mlx, 0, sizeof(t_mlx));
	if (ac == 2)
	{
		int fd = open(av[1], O_RDONLY);
		ft_printf("file %d\n", fd);
		if (ft_validation(fd, &mlx))
		{
			ft_printf("Reading from file...\n");
			ft_get_pts_array(av[1], &mlx);
			ft_run_mlx(&mlx);
		}
		else
		{
			ft_printf("Not valid file: %s\n", av[1]);
			exit(0);
		}
	}
	else
		ft_printf("usage: ./fdf source_file\n");
	return (0);
}