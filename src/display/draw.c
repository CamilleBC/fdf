/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:54:23 by cbaillat          #+#    #+#             */
/*   Updated: 2019/06/04 16:11:46 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "projection.h"

/*
** We are using Bresenham's line algorithm:
** https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
**
** We check the direction we need to go, depending on the position of A compared
** to B, we change the step for each pixel to (1) or (-1).
*/
void draw_line(t_fdf *fdf, t_point a, t_point b, int colour)
{
	// dbg:
	(void)colour;
	t_point delta;
	t_point step;
	t_point start;
	int     error;
	int     next_error;

	start = a;
	delta.x = abs(b.x - a.x);
	delta.y = -abs(b.y - a.y);
	step.x = a.x < b.x ? 1 : -1;
	step.y = a.y < b.y ? 1 : -1;
	error = delta.x + delta.y;
	while ((a.x != b.x) || (a.y != b.y))
	{
		fill_pixel(fdf, a.x, a.y, get_color(a, start, b, delta));
		next_error = 2 * error;
		if (next_error >= delta.y)
		{
			error += delta.y;
			a.x += step.x;
		}
		if (next_error <= delta.x)
		{
			error += delta.x;
			a.y += step.y;
		}
	}
}

void	draw_map(t_fdf *fdf)
{
	int			i;
	int			j;

	create_image(fdf);
	j = -1;
	while (++j < fdf->map->height)
	{
		i = -1;
		while (++i < fdf->map->width)
		{
			apply_transfo(fdf, i, j);
		}
	}
	mlx_put_image_to_window(fdf->window->mlx_ptr, fdf->window->win_ptr
		, fdf->img->ptr, 0, 0);
}

void fill_pixel(t_fdf *fdf, int x, int y, int color)
{
	// printf("DEBUG fill in x = %d, y = %d\n", x, y);
	unsigned int		*img_cast;
	if (x < SCR_WIDTH && x >= 0 && y >= 0 && y < SCR_HEIGTH )
	{
		img_cast = (unsigned int *)(fdf->img->str);
		img_cast[y * SCR_WIDTH + x] = color;
	}
	// printf("DEBUG fill out x = %d, y = %d\n", x, y);
}
