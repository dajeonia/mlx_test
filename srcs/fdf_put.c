/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_put_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:18:40 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 10:34:01 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_putmap(t_vars *vars, t_dot ***map)
{
	t_img	*img;

	img = fdf_image_init(vars);
	fdf_image_set_map(vars, img, map);
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
	fdf_image_destroy(vars, img);
}

/*
void	fdf_putdot(t_vars *vars, t_dot *dot)
{
	t_img	*img;

	img = fdf_image_init(vars);
	fdf_image_set(img, 25, 90, dot->color);
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
	fdf_image_destroy(vars, img);
}
*/
