/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:29:02 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/06 18:31:21 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int kill(void *param) { 
    printf ("Kill!");

    t_window *window = (t_window *)param;
    mlx_destroy_window(window->mlx_ptr,window->window_ptr);
    exit(0);
     
    return 0; 
} 