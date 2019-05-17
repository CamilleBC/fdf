/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:52:17 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/17 15:37:57 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char *argv[])
{
	t_fdf 			*fdf;
	t_projection	proj;
	int				zoom;
	t_resolution	res;

	if (argc != 2)
	{
		error_fdf(NULL, "Wrong number of arguments.\n");
		return (EXIT_FAILURE);
	}
	zoom = 1;
	proj = ISO;
	res.x = 2000;
	res.y = 1500;
	if ((fdf = init_fdf()) == NULL)
		return (EXIT_FAILURE);
	if ((fdf->camera = init_camera(proj, zoom)) == NULL
		|| (fdf->map = init_map()) == NULL
		|| (fdf->window = init_window(res)) == NULL)
		error_fdf(fdf, NULL);
	parse_map(fdf, argv[1]);
	create_window(fdf);
	return (EXIT_SUCCESS);
}
