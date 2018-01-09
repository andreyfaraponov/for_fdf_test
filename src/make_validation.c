/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:06:47 by afarapon          #+#    #+#             */
/*   Updated: 2018/01/08 20:48:07 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_count(char *str)
{
	int		count;

	count = 0;
	while (str && *str && (*str == ' ' || *str == ',' || ft_isdigit(*str) || ((*str == '-') && ft_isdigit(*(str + 1))) ||
		((*str == 'x') && *(str - 1) == '0' && (ft_isdigit(*(str + 1)) || (*(str + 1) >= 'A' && *(str + 1) <= 'F'))) ||
		(*str >= 'A' && *str <= 'F')))
	{
		if (*str == ' ')
			count++;
		str++;
	}
	return (count);
}

int			ft_validation(int fd, t_mlx *mlx)
{
	int		width;
	int		lines;
	char	*line;
	int		last;

	get_next_line(fd, &line);
	width = ft_count(line);
	lines = width ? 1 : 0;
	while (get_next_line(fd, &line) > 0)
	{
		last = width;
		if (*line == '\0')
			continue ;
		if ((width = ft_count(line)) == last)
			lines++;
		if (width != last || !width)
			return (0);
	}
	mlx->x_pts_size = width;
	mlx->y_pts_size = lines;
	ft_printf("%-15s%5d\n%-15s%5d\n", "Array Width:", mlx->x_pts_size, "Array Height:", mlx->y_pts_size);
	close(fd);
	return (1);
}