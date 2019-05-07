/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:54:23 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/07 17:25:50 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "error.h"
#include "events.h"

void draw_line(t_window *window, t_point a, t_point b, int colour)
{
    t_point     delta;
    t_point     step;
    int error;
    int next_error;

    delta.x = abs(b.x - a.x);
    delta.y = -abs(b.y - a.y);
    step.x = a.x < b.x ? 1 : -1;
    step.y = a.y < b.y ? 1 : -1;
    error = delta.x + delta.y;
    while (a.x != b.x - 1 && a.y != b.y - 1)
    {
        mlx_pixel_put(window->mlx_ptr, window->window_ptr, a.x, a.y, colour);
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

int draw_map(t_fdf *fdf)
{
    t_window *window;

    window = fdf->window;

    if ((check_null(fdf->window->mlx_ptr = mlx_init()) == EXIT_FAILURE) 
    || (check_null(fdf->window->window_ptr = mlx_new_window(
        fdf->window->mlx_ptr, 1000, 1000, "fdf")) == EXIT_FAILURE))
        return EXIT_FAILURE;
    mlx_key_hook(fdf->window->window_ptr, deal_key, (void *)fdf);
    mlx_loop(fdf->window->mlx_ptr);
    return EXIT_SUCCESS;
}