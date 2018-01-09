/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:26:37 by afarapon          #+#    #+#             */
/*   Updated: 2018/01/08 17:02:06 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_window_init(t_mlx *mlx)
{
	mlx->init = mlx_init();
	mlx->window = mlx_new_window(mlx->init, W_X_SIZE, W_Y_SIZE, W_NAME);
	ft_printf("Init %s\n", W_NAME);
}

void			ft_redraw(t_mlx *mlx)
{
	(void)mlx;
}