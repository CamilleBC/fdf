/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:05:27 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/17 14:38:11 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
#define DRAW_H

#include "colours.h"
#include "error.h"
#include "events.h"
#include "mlx.h"
#include "typedefs.h"

void draw_line(t_fdf *fdf, t_point a, t_point b, int colour);
void fill_pixel(t_fdf *fdf, int x, int y, int color);


#endif /* DRAW_H */
