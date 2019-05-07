/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:29:02 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/07 16:56:05 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int deal_key(int key, void *param)
{
    ft_print("key pressed: %x\n", key);
    t_fdf   *fdf;
    t_point a;
    t_point b;

    fdf = (t_fdf *)param;
    a.x = 00;
    a.y = 00;
    b.x = 30;
    b.y = 800;
    
    switch (key)
    {
        case KEY_ENTER:
            draw_line(fdf->window, a, b, GREEN);
            break;
        case KEY_ESCAPE:
            kill_window(fdf);
            break;
        default:
            return 1;
            break;
    }
    return 0;
}

void kill_window(t_fdf *fdf)
{ 
    mlx_destroy_window(fdf->window->mlx_ptr, fdf->window->window_ptr);
    free_fdf_struct(fdf);
    exit(EXIT_SUCCESS);
} 