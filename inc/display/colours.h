/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:34:39 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/24 13:25:33 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOURS_H
#define COLOURS_H

#include "typedefs.h"

#define BLACK 	0x000000
#define WHITE 	0xFFFFFF
#define RED 	0xFF0000
#define LIME 	0x00FF00
#define BLUE 	0x0000FF
#define YELLOW 	0xFFFF00
#define CYAN 	0x00FFFF
#define MAGENTA 0xFF00FF
#define SILVER 	0xC0C0C0
#define GRAY 	0x808080
#define MAROON 	0x800000
#define OLIVE 	0x808000
#define GREEN 	0x008000
#define PURPLE 	0x800080
#define TEAL 	0x008080
#define NAVY 	0x000080

double percent(int start, int end, int current);
int get_light(int start, int end, double percentage);
int get_color(t_point current, t_point start, t_point end, t_point delta);
int	get_point_color(int z, int zmax);

#endif /* COLOURS_H */
