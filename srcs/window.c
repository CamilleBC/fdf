/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 10:46:27 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/17 13:53:14 by klebon           ###   ########.fr       */
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
		|| (win->win_ptr = mlx_new_window(win->mlx_ptr, win->res.x, win->res.y
			, "fdf")) == NULL)
		error_fdf(fdf, "Error: cannot create display window.\n");
	create_image(fdf);
	mlx_key_hook(win->win_ptr, deal_key, (void *)fdf);
	mlx_loop(win->mlx_ptr);
}

void	create_image(t_fdf *fdf)
{
	t_window	*win;
	int			bpp;
	int			s_l;
	int			endian;

	win = fdf->window;
	if (!(fdf->img = (t_image *)malloc(sizeof(t_image))))
		return ;
	fdf->img->ptr = mlx_new_image(win->mlx_ptr, win->res.x, win->res.y);
	fdf->img->str = mlx_get_data_addr(fdf->img->ptr, &(bpp), &(s_l), &(endian));
}
