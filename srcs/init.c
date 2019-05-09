/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 09:58:02 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/09 14:06:03 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_map *init_map()
{
	t_map *map;

	if ((map = (t_map *) malloc(sizeof(t_map))) == NULL)
		return NULL;
	map->array = NULL;
	map->x = INVALID;
	map->y = INVALID;
	return map;
}

t_window *init_window(t_resolution res)
{
	t_window *window;
	if ((window = (t_window *) malloc(sizeof(t_window))) == NULL)
		return NULL;
	window->mlx_ptr = NULL;
	window->win_ptr = NULL;
	window->res.x = res.x;
	window->res.y = res.y;
	return window;
}
