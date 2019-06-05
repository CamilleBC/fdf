/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camille <camille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 16:29:25 by cbaillat          #+#    #+#             */
/*   Updated: 2019/06/05 10:07:05 by camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_H
#define PROJECTION_H

#include "colours.h"
#include "draw.h"
#include "typedefs.h"
#include <math.h>

void	draw_map(t_fdf *fdf);
void	mult_mat(double m1[3][3], double m2[3][3]);
void	mult_rot(t_fdf *fdf, int x, int y, t_3dpoint *p);
t_point	project_parallele(t_3dpoint *p);
void	set_idmat(t_fdf *fdf);
void	set_rotx(double mat[3][3]);
void	set_roty(double mat[3][3]);
void	set_rotz(double mat[3][3]);


#endif /* PROJECTION_H */
