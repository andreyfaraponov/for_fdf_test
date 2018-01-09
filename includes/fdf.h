/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:06:05 by afarapon          #+#    #+#             */
/*   Updated: 2018/01/09 15:54:39 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
# ifndef FDF_H
# define FDF_H
# define W_X_SIZE 800
# define W_Y_SIZE 800
# define W_NAME "TEST WINDOW"
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# include <mlx.h>
# include <math.h>
# include <fcntl.h>

typedef struct			s_point
{
	double				x;
	double				y;
	double				z;
	int					color;
}						t_point;

typedef struct			s_mlx
{
	void				*init;
	void				*window;
	double				x_offset;
	double				y_offset;
	int					**points;
	int					x_pts_size;
	int					y_pts_size;
}						t_mlx;

void					ft_window_init(t_mlx *mlx);
void					ft_exit(t_mlx *mlx);

/*
**	KEYHOOKS
*/

void					ft_left(t_mlx *mlx);
void					ft_right(t_mlx *mlx);
void					ft_down(t_mlx *mlx);
void					ft_up(t_mlx *mlx);

/*
**	VALIDATION
*/

int						ft_validation(int fd, t_mlx *mlx);

/*
**	RETRIVE DATA
*/

void					ft_get_pts_array(char *fname, t_mlx *mlx);

#endif