/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 10:46:27 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/09 14:50:17 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void create_window(t_map *map, t_window *win)
{
	t_fdf fdf;

	if ((win->mlx_ptr = mlx_init()) == NULL
		|| (win->win_ptr = mlx_new_window(win->mlx_ptr, win->res.x, win->res.y
			, "fdf")) == NULL)
		error_fdf(map, win, "Error: cannot create display window.\n");
	fdf.map = map;
	fdf.window = win;
	mlx_key_hook(win->win_ptr, deal_key, (void *) &fdf);
	mlx_loop(win->mlx_ptr);
}
