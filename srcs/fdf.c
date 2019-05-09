/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:52:17 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/09 14:06:14 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char *argv[])
{
	t_map 			*map;
	t_window		*window;
	t_resolution	res;

	if (argc != 2)
	{
		error_fdf(NULL, NULL, "Wrong number of arguments.\n");
		return (EXIT_FAILURE);
	}
	if ((map = init_map()) == NULL)
		return (EXIT_FAILURE);
	res.x = 800;
	res.y = 600;
	if ((window = init_window(res)) == NULL)
		error_fdf(map, NULL, NULL);
	parse_map(map, argv[1]);
	create_window(map, window);
	return (EXIT_SUCCESS);
}
