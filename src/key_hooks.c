/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:44:46 by afarapon          #+#    #+#             */
/*   Updated: 2018/01/08 16:06:56 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_exit(t_mlx *mlx)
{
		mlx_destroy_window(mlx->init, mlx->window);
		exit(0);
}

void		ft_left(t_mlx *mlx)
{
	(void)mlx;
	ft_printf("LEFT TRIGGER\n");
}

void		ft_right(t_mlx *mlx)
{
	(void)mlx;
	ft_printf("RIGHT TRIGGER\n");
}

void		ft_down(t_mlx *mlx)
{
	(void)mlx;
	ft_printf("DOWN TRIGGER\n");
}

void		ft_up(t_mlx *mlx)
{
	(void)mlx;
	ft_printf("UP TRIGGER\n");
}