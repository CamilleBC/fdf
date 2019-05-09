/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 09:54:17 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/09 16:19:39 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
#define INIT_H

/*
** error.h -> EXIT & INVALID defines
** typedefs.h -> custom types
*/
#include "error.h"
#include "typedefs.h"

t_camera	*init_camera(t_projection projection, int zoom);
t_fdf		*init_fdf(void);
t_map		*init_map(void);
t_window	*init_window(t_resolution res);

#endif /* INIT_H */
