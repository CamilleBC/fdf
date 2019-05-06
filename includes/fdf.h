/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:59:35 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/06 18:41:26 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "colours.h"
#include "keycodes.h"

typedef struct  s_window
{
    void    *mlx_ptr;
    void    *window_ptr;
}               t_window;

int draw_horizontal_line(t_window *win, int x, int y, int length, int colour);
int kill(void *param);