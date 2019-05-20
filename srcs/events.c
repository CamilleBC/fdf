/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:29:02 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/20 16:59:20 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int deal_key(int key, void *param)
{
	t_fdf 	*fdf;

	fdf = (t_fdf*) param;
	if (key == KEY_ENTER)
	{
		draw_map(fdf);
		mlx_put_image_to_window(fdf->window->mlx_ptr, fdf->window->win_ptr
			, fdf->img->ptr, 0, 0);
	}
	else if (key == KEY_X)
		key_x(fdf);
	else if (key == KEY_Y)
		key_y(fdf);
	else if (key == KEY_Z)
			key_z(fdf);
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

void	key_x(t_fdf *fdf)
{
	mult_mat(fdf->rot, fdf->rotx);
	mlx_clear_window(fdf->window->mlx_ptr, fdf->window->win_ptr);
	draw_map(fdf);
	mlx_put_image_to_window(fdf->window->mlx_ptr, fdf->window->win_ptr
		, fdf->img->ptr, 0, 0);
}

void	key_y(t_fdf *fdf)
{
	mult_mat(fdf->rot, fdf->roty);
	mlx_clear_window(fdf->window->mlx_ptr, fdf->window->win_ptr);
	draw_map(fdf);
	mlx_put_image_to_window(fdf->window->mlx_ptr, fdf->window->win_ptr
		, fdf->img->ptr, 0, 0);
}

void	key_z(t_fdf *fdf)
{
	mult_mat(fdf->rot, fdf->rotz);
	mlx_clear_window(fdf->window->mlx_ptr, fdf->window->win_ptr);
	draw_map(fdf);
	mlx_put_image_to_window(fdf->window->mlx_ptr, fdf->window->win_ptr
		, fdf->img->ptr, 0, 0);
}
