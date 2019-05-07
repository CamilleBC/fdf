/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:59:35 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/07 16:49:02 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H   
#define FDF_H   

#include "libft.h"
#include <math.h>

typedef struct  s_window
{
    void    *mlx_ptr;
    void    *window_ptr;
}               t_window;

typedef struct  s_map
{
    int     x;
    int     y;
    int     *array;
}               t_map;

typedef struct  s_fdf
{
    t_window    *window;
    t_map       *map;
}               t_fdf;

void    free_fdf_struct(t_fdf *fdf);
int     init_fdf_struct(t_fdf **fdf_ptr);

#endif /* FDF_H */