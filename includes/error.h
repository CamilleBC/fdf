/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 09:17:26 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/07 09:19:48 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
#define ERROR_H

/*
** free.h -> Free structures
** stdio.h -> STD defines & write
** stdlib.h -> EXIT defines
** typedefs.h -> custom types
*/
#include "free.h"
#include "typedefs.h"
#include <stdlib.h>
#include <unistd.h>

#define INVALID -1

void error_fdf(t_fdf *fdf, char *error_msg);

#endif /* ERROR_H */
