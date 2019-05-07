/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:54:23 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/07 13:52:03 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "error.h"
#include "events.h"

int draw_line(t_fdf *fdf, t_point a, t_point b, int colour)
{
    t_window    window;
    t_point     i;
    double      error;
    double      slope;
    
    window = *(fdf->window);
    i.x = a.x;
    i.y = a.y;
    error = -0.5;
    slope = ((double)b.x - (double)a.x) / ((double)b.y - (double)a.y);

    while (i.x < b.x) {
        mlx_pixel_put(window.mlx_ptr, window.window_ptr, i.x, i.y, colour);
        if ((error += slope) > 0.0)
        {
            i.y++;
            error -= 1;
        }
        i.x++;
    }
    return EXIT_SUCCESS;
}

int draw_map(t_fdf *fdf)
{
    t_window    *window;
    
    window = fdf->window;

    if ((check_null(fdf->window->mlx_ptr = mlx_init()) == EXIT_FAILURE)
        || (check_null(fdf->window->window_ptr = mlx_new_window(
            fdf->window->mlx_ptr, 1000, 1000, "fdf")) == EXIT_FAILURE))
        return EXIT_FAILURE;

    mlx_key_hook(fdf->window->window_ptr, deal_key, (void *)fdf);
    mlx_loop(fdf->window->mlx_ptr);
    return EXIT_SUCCESS;
}