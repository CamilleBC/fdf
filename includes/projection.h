/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 16:29:25 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/21 17:17:51 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_H
#define PROJECTION_H

#include "typedefs.h"
#include "colours.h"
#include "draw.h"

void	set_idmat(t_fdf *fdf);
void	set_rotx(double mat[3][3]);
void	set_roty(double mat[3][3]);
void	set_rotz(double mat[3][3]);
void	mult_mat(double m1[3][3], double m2[3][3]);
void	draw_map(t_fdf *fdf);


#endif /* PROJECTION_H */
