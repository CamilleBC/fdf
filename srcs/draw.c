/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:54:23 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/06 18:41:13 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int draw_horizontal_line(t_window *win, int x, int y, int length, int colour) {

    int currentx = x;
    int endx = x + length;

    while (currentx++ <= endx) {
        mlx_pixel_put(win->mlx_ptr, win->window_ptr, currentx, y, colour);
    }
    return 0;
}