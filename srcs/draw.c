/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:54:23 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/22 15:22:55 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

/*
** We are using Bresenham's line algorithm:
** https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
**
** We check the direction we need to go, depending on the position of A compared
** to B, we change the step for each pixel to (1) or (-1).
*/
// void draw_line(t_map *map, t_point a, t_point b, int colour)
void draw_line(t_fdf *fdf, t_point a, t_point b, int colour)
{
	// printf("DEBUG draw\n");
	t_point delta;
	t_point step;
	int     error;
	int     next_error;

	delta.x = abs(b.x - a.x);
	delta.y = -abs(b.y - a.y);
	step.x = a.x < b.x ? 1 : -1;
	step.y = a.y < b.y ? 1 : -1;
	error = delta.x + delta.y;
	while ((a.x != b.x) || (a.y != b.y))
	{
		fill_pixel(fdf, a.x, a.y, colour);
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
	// printf("DEBUG draw out\n");
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
