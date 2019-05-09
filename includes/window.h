/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 10:46:46 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/09 13:47:17 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
#define WINDOW_H

/*
** error.h		-> Error management
** events.h		-> Handle events in MiniLibX loop
** mlx.h		-> MiniLibX library
** typedefs.h	-> Custome types
*/
#include "error.h"
#include "events.h"
#include "mlx.h"
#include "typedefs.h"

void create_window(t_map *map, t_window *win);

#endif /* WINDOW_H */
