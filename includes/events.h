/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 09:56:07 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/17 15:21:00 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
#define EVENTS_H

/*
** free.h -> Free the fdf on KEY_ESCAPE
** keycodes.h -> Key codes...
** stdlib.h -> EXIT defines
** typedefs.h -> Custom types
*/
#include "draw.h"
#include "window.h"
#include "free.h"
#include "keycodes.h"
#include "typedefs.h"
#include "projection.h"
#include <stdlib.h>

int deal_key(int key, void *param);
void kill_window(t_fdf *fdf);

#endif /* EVENTS_H */
