/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 09:52:15 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/09 16:26:12 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FREE_H
#define FREE_H

#include "typedefs.h"
#include "mlx.h"
#include <stdio.h>

void free_camera(t_camera *camera);
void free_fdf(t_fdf *fdf);
void free_map(t_map *map);
void free_window(t_window *window);

#endif /* FREE_H */
