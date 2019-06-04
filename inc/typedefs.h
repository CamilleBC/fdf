/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 08:34:10 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/24 12:12:44 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#define SCR_WIDTH	1500
#define SCR_HEIGTH	1500

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
	int	color;
}				t_point;

typedef struct	s_3dpoint
{
	double		x;
	double		y;
	double		z;
	double		zmax;
}				t_3dpoint;

typedef struct	s_image
{
	void		*ptr;
	char		*str;
}				t_image;

typedef struct	s_window
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*image_ptr;
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
	t_image		*img;
	double		rot[3][3];
	double		rotx[3][3];
	double		roty[3][3];
	double		rotz[3][3];
	int			movex;
	int			movey;
	int			alt;
	double		movez;
	double		zoom;
	int			zmax;
}				t_fdf;

#endif /* TYPEDEFS_H */
