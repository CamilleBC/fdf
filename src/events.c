/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:29:02 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/21 18:55:24 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int deal_key(int key, void *param)
{
	t_fdf 	*fdf;

	fdf = (t_fdf*) param;
	if (key == K_ENTER)
	{
		set_idmat(fdf);
		mlx_clear_window(fdf->window->mlx_ptr, fdf->window->win_ptr);
		draw_map(fdf);
	}
	else if (key == K_X || key == K_Y || key == K_Z)
		rotate(fdf, key);
	else if (key == K_LEFT || key == K_RIGHT || key == K_UP || key == K_DOWN
		|| key == K_PGUP || key == K_PGDOWN)
		move(fdf, key);
	else if (key == K_MULT || key == K_DIVID || key == K_PLUS || key == K_MINUS)
		zoom(fdf, key);
	else if (key == K_ESCAPE)
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

void	rotate(t_fdf *fdf, int key)
{
	if (key == K_X)
		mult_mat(fdf->rot, fdf->rotx);
	else if (key == K_Y)
		mult_mat(fdf->rot, fdf->roty);
	else
		mult_mat(fdf->rot, fdf->rotz);
	mlx_clear_window(fdf->window->mlx_ptr, fdf->window->win_ptr);
	draw_map(fdf);
}

void 	move(t_fdf *fdf, int key)
{
	if (key == K_LEFT)
		fdf->movex -= 5;
	else if (key == K_RIGHT)
		fdf->movex += 5;
	else if (key == K_UP)
		fdf->movey -= 5;
	else if (key == K_DOWN)
		fdf->movey += 5;
	else if (key == K_PGUP)
		fdf->movez += 5;
	else if (key == K_PGDOWN)
		fdf->movez -= 5;
	mlx_clear_window(fdf->window->mlx_ptr, fdf->window->win_ptr);
	draw_map(fdf);
}

void 	zoom(t_fdf *fdf, int key)
{
	if (key == K_MULT)
		fdf->zoom += 0.1;
	else if (key == K_DIVID && fdf->zoom -0.1 > 0)
		fdf->zoom -= 0.1;
	else if (key == K_PLUS)
		fdf->alt += 1;
	else if (key == K_MINUS)
		fdf->alt -= 1;
	mlx_clear_window(fdf->window->mlx_ptr, fdf->window->win_ptr);
	draw_map(fdf);
}
