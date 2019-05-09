/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:05:27 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/09 16:34:34 by cbaillat         ###   ########.fr       */
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
int  draw_map(t_map *map, t_window *window);

#endif /* DRAW_H */
