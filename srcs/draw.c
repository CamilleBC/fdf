/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:54:23 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/09 14:54:08 by cbaillat         ###   ########.fr       */
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
void draw_line(t_window *win, t_point a, t_point b, int colour)
{
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
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, a.x, a.y, colour);
		// fill_pixel(win->image_string, a, win.res, colour);
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

/*
** Use a binary mask to set the pixels color
*/
void fill_pixel(char **image_string, t_point pixel, t_resolution res, int colour)
{
	int x_index;
	int y_index;
	int pixel_ptr;

	x_index = pixel.x * (4 * sizeof(char));
	y_index = pixel.y * (res.x * sizeof(char));
	pixel_ptr = x_index + y_index;

	// DEBUG
	printf("Pixel X: %d\n", x_index);
	printf("Pixel Y: %d\n", y_index);
	printf("Pixel: %x\n",image_string[pixel_ptr]);
	(*image_string)[pixel_ptr] = colour;
}
