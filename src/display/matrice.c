/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camille <camille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:19:40 by klebon            #+#    #+#             */
/*   Updated: 2019/06/05 10:17:56 by camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"

void	set_idmat(t_fdf *fdf)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
		{
			if (i == j && i == 2)
				fdf->rot[i][j] = 1.00;
			else if (i == j)
				fdf->rot[i][j] = 10.00;
			else
				fdf->rot[i][j] = 0.00;

		}
	}
	fdf->movex = SCR_WIDTH / 2;
	fdf->movey = 0;
	fdf->movez = 0.00;
	fdf->zoom = 1.00;
	fdf->alt = 1;
}

void	set_rotx(double mat[3][3])
{
	int		i;
	int		j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			mat[i][j] = 0.00;
	}
	mat[0][0] = 1;
	mat[1][1] = cos((double)0.1);
	mat[2][2] = cos((double)0.1);
	mat[1][2] = sin((double)0.1);
	mat[2][1] = -sin((double)0.1);
}

void	set_roty(double mat[3][3])
{
	int		i;
	int		j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			mat[i][j] = 0.00;
	}
	mat[0][0] = cos(0.1);
	mat[1][1] = 1;
	mat[2][2] = cos(0.1);
	mat[2][0] = sin(0.1);
	mat[0][2] = -sin(0.1);
}

void	set_rotz(double mat[3][3])
{
	int		i;
	int		j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			mat[i][j] = 0.00;
	}
	mat[0][0] = cos(0.1);
	mat[1][1] = cos(0.1);
	mat[2][2] = 1;
	mat[0][1] = sin(0.1);
	mat[1][0] = -sin(0.1);
}

void	mult_mat(double m1[3][3], double m2[3][3])
{
	int		i;
	int		j;
	int		k;
	double	res[3][3];

	i = -1;
	while(++i < 3)
	{
		j = -1;
		while (++j < 3)
		{
			k = -1;
			res[i][j] = 0.00;
			while (++k < 3)
				res[i][j] += m1[i][k]*m2[k][j];
		}
	}
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			m1[i][j] = res[i][j];
	}
}
