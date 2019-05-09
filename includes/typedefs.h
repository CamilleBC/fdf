/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 08:34:10 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/09 16:37:27 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
#define TYPEDEFS_H

typedef enum	e_projection
{
	ISO,
	CONIC,
	PARALLEL
}				t_projection;

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_res
{
	int x;
	int y;
}				t_resolution;

typedef struct	s_window
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*image_ptr;
	t_resolution	res;
}				t_window;

typedef struct	s_map
{
	int   x;
	int   y;
	int **array;
}				t_map;

typedef struct	s_camera
{
	t_projection	projection;
	int				zoom;
}				t_camera;

typedef struct	s_fdf
{
	t_map		*map;
	t_window	*window;
	t_camera	*camera;
}				t_fdf;

#endif /* TYPEDEFS_H */
