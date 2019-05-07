/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:05:27 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/07 16:50:49 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
#define DRAW_H

#include "colours.h"
#include "fdf.h"
#include "mlx.h"

typedef struct  s_fdf       t_fdf;

typedef struct  s_point
{
    int x;
    int y;
}               t_point;

void draw_line(t_window *window, t_point a, t_point b, int colour);
int draw_map(t_fdf *fdf);

#endif /* DRAW_H */