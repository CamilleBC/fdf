/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:29:02 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/17 15:20:36 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int deal_key(int key, void *param)
{
	t_fdf 	*fdf;
	t_point a;
	t_point b;

	fdf = (t_fdf*) param;
	a.x = 0;
	a.y = 0;
	b.x = 800;
	b.y = 300;

	if (key == KEY_ENTER)
	{
		draw_map(fdf);
		mlx_put_image_to_window(fdf->window->mlx_ptr, fdf->window->win_ptr
			, fdf->img->ptr, 0, 0);
	}
	else if (key == KEY_ESCAPE)
		kill_window(fdf);
	return (EXIT_SUCCESS);
}

void kill_window(t_fdf *fdf)
{
	mlx_destroy_window(fdf->window->mlx_ptr, fdf->window->win_ptr);
	fdf->window->win_ptr = NULL;
	free_fdf(fdf);
	exit(EXIT_SUCCESS);
}
