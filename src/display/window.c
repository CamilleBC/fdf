/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 10:46:27 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/09 16:36:35 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void create_window(t_fdf *fdf)
{
	t_map		*map;
	t_window	*win;

	map = fdf->map;
	win = fdf->window;

	if ((win->mlx_ptr = mlx_init()) == NULL
		|| (win->win_ptr = mlx_new_window(win->mlx_ptr, win->res.x, win->res.y
			, "fdf")) == NULL)
		error_fdf(fdf, "Error: cannot create display window.\n");
	mlx_key_hook(win->win_ptr, deal_key, (void *)fdf);
	mlx_loop(win->mlx_ptr);
}
