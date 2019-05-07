/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 09:56:07 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/07 16:51:29 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
#define EVENTS_H

#include "fdf.h"
#include "draw.h"
#include "keycodes.h"

typedef struct s_point t_point;

int deal_key(int key, void *param);
void kill_window(t_fdf *fdf);

#endif /* EVENTS_H */