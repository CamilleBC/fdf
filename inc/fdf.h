/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:59:35 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/09 13:48:45 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

/*
**	init.h		-> Initialise structures
**	error.h		-> Error management
**	free.h		-> Free structures
**	parser.h	-> Parse the input map
**	typedefs.h	-> Custom types
**	window.h	-> Handle the window creation and mlx loop
*/
#include "draw.h"
#include "error.h"
#include "free.h"
#include "init.h"
#include "parser.h"
#include "typedefs.h"
#include "window.h"

/* DEBUG */
void print_map(t_map *map);

#endif /* FDF_H */
