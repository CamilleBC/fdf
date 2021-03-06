/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 09:34:28 by cbaillat          #+#    #+#             */
/*   Updated: 2019/06/04 16:12:04 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"

/*
** This file holds all functions related to transforming into its iso, parallel,
** or conic projection.
*/
t_point	project_parallele(t_3dpoint *p)
{
	// printf("DEBUG project\n");
	t_point		a;
	double		n;
	//int			endy;

	n = 0.1;
	// a.x = (int)(p->x + n * p->z);
	// a.y = (int)(p->y + n / 2 * p->z);
	a.x = (int)((p->x - p->y) * cos((double)0.523599));
	a.y = (int)(-p->z + (p->x + p->y) * sin((double)0.523599));
	// endy = (int)(-p->zmax + (p->x + p->y) * sin(0.523599));
	// a.color = get_point_color(a, endy);
	// a.x = (int)p->x;
	// a.y = (int)(-p->z);
	return (a);
}

void	mult_rot(t_fdf *fdf, int x, int y, t_3dpoint *p)
{
	// printf("DEBUG mult\n");
	int		**map;

	map = fdf->map->array;
	p->x = (x * fdf->rot[0][0] + y * fdf->rot[1][0] + (map[y][x] * fdf->alt) * fdf->rot[2][0])
		* fdf->zoom + fdf->movex;
	p->y = (x * fdf->rot[0][1] + y * fdf->rot[1][1] + (map[y][x] * fdf->alt) * fdf->rot[2][1])
		* fdf->zoom + fdf->movey;
	p->z = (x * fdf->rot[0][2] + y * fdf->rot[1][2] + (map[y][x] * fdf->alt) * fdf->rot[2][2])
		* fdf->zoom + fdf->movez;
	// p->zmax = (x * fdf->rot[0][2] + y * fdf->rot[1][2] + (fdf->zmax * fdf->alt) * fdf->rot[2][2])
	// 	* fdf->zoom + fdf->movez;
}

void 	apply_transfo(t_fdf *fdf, int x, int y)
{
	t_point	a;
	t_point	b;
	t_3dpoint	pt[3];

	mult_rot(fdf, x, y, &pt[0]);
	a = project_parallele(&pt[0]);
	a.color = get_point_color(fdf->map->array[y][x], fdf->zmax);
	if (x + 1 < fdf->map->width)
	{
		mult_rot(fdf, x + 1, y, &pt[1]);
		b = project_parallele(&pt[1]);
		b.color = get_point_color(fdf->map->array[y][x + 1], fdf->zmax);
		draw_line(fdf, a, b, (fdf->map->array[y][x + 1] == 10
			|| fdf->map->array[y][x] == 10) ? GREEN : RED);
	}
	if (y + 1 < fdf->map->height)
	{
		mult_rot(fdf, x, y + 1, &pt[2]);
		b = project_parallele(&pt[2]);
		b.color = get_point_color(fdf->map->array[y + 1][x], fdf->zmax);
		draw_line(fdf, a, b, (fdf->map->array[y + 1][x] == 10
			|| fdf->map->array[y][x] == 10) ? GREEN : RED);
	}
}

