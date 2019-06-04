/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 09:58:02 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/23 12:06:33 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_fdf *init_fdf(void)
{
	t_fdf *   fdf;
	t_map *   map;
	t_window *window;
	t_camera *camera;

	if ((fdf = (t_fdf *) malloc(sizeof(t_fdf))) == NULL)
		return NULL;
	fdf->camera = NULL;
	fdf->map = NULL;
	fdf->window = NULL;
	set_idmat(fdf);
	set_rotx(fdf->rotx);
	set_roty(fdf->roty);
	set_rotz(fdf->rotz);
	fdf->zmax = 0;
	return fdf;
}

t_camera *init_camera(t_projection projection, int zoom)
{
	t_camera *camera;

	if ((camera = (t_camera *) malloc(sizeof(t_camera))) == NULL)
		return NULL;
	camera->projection = projection;
	camera->zoom = zoom;
	return camera;
}

t_map *init_map(void)
{
	t_map *map;

	if ((map = (t_map *) malloc(sizeof(t_map))) == NULL)
		return NULL;
	map->array = NULL;
	map->x = INVALID;
	map->y = INVALID;
	return map;
}

t_window *init_window(void)
{
	t_window *window;
	if ((window = (t_window *) malloc(sizeof(t_window))) == NULL)
		return NULL;
	window->mlx_ptr = NULL;
	window->win_ptr = NULL;
	return window;
}
