/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 16:29:25 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/17 15:24:30 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_H
#define PROJECTION_H

#include "typedefs.h"
#include "colours.h"
#include "draw.h"

void	set_idmat(double mat[3][3]);
void	draw_map(t_fdf *fdf);


#endif /* PROJECTION_H */
