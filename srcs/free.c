/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 09:49:15 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/09 16:26:26 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void free_camera(t_camera *camera)
{
	if (camera != NULL)
	{
		free(camera);
	}
}

void free_fdf(t_fdf *fdf)
{
	if (fdf != NULL)
	{
		free_camera(fdf->camera);
		free_map(fdf->map);
		free_window(fdf->window);
		free(fdf);
	}
}

void free_map(t_map *map)
{
	int i;

	if (map != NULL)
	{
		if (map->array != NULL)
		{
			i = 0;
			while (i++ < map->y)
				free(map->array[i]);
			free(map->array);
		}
		free(map);
	}
}

void free_window(t_window *window)
{
	if (window != NULL)
	{
		if (window->win_ptr != NULL)
			mlx_destroy_window(window->mlx_ptr, window->win_ptr);
		if (window->mlx_ptr != NULL)
			free(window->mlx_ptr);
		free(window);
	}
}
