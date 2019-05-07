/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 09:56:07 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/07 11:16:46 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
#define EVENTS_H

#include "fdf.h"
#include "keycodes.h"

int deal_key(int key, void *param);
void kill_window(t_fdf *fdf);

#endif /* EVENTS_H */