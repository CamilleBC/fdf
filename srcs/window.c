/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 10:46:27 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/22 15:07:22 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	create_window(t_fdf *fdf)
{
	t_map		*map;
	t_window	*win;

	map = fdf->map;
	win = fdf->window;

	if ((win->mlx_ptr = mlx_init()) == NULL
		|| (win->win_ptr = mlx_new_window(win->mlx_ptr, SCR_WIDTH, SCR_HEIGTH
			, "fdf")) == NULL)
		error_fdf(fdf, "Error: cannot create display window.\n");
	if (!(fdf->img = (t_image *)malloc(sizeof(t_image))))
		return ;
	draw_map(fdf);
	mlx_hook(win->win_ptr, 2, 0, deal_key, (void *)fdf);
	mlx_loop(win->mlx_ptr);
}

void	create_image(t_fdf *fdf)
{
	t_window	*win;
	int			bpp;
	int			s_l;
	int			endian;

	win = fdf->window;
	// mlx_destroy_image(win->mlx_ptr, fdf->img->ptr);
	fdf->img->ptr = mlx_new_image(win->mlx_ptr, SCR_WIDTH, SCR_HEIGTH);
	fdf->img->str = mlx_get_data_addr(fdf->img->ptr, &(bpp), &(s_l), &(endian));
}
