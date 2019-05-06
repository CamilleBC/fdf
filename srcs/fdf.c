/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:52:17 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/06 18:41:53 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int deal_key(int key, void *param) {
    ft_print("key pressed: %x\n", key);
    
    switch (key)
    {
        case KEY_ENTER:
            draw_horizontal_line(param, 50, 50, 200, GREEN);
            break;
        case KEY_ESCAPE:
            kill(param);
            break;
        default:
            return 1;
            break;
    }
    return 0;
}

// int main (int argc, char *argv[]) { 
int main() { 
    
    t_window *window = (t_window *)malloc(sizeof(t_window));

    window->mlx_ptr = mlx_init();
    window->window_ptr = mlx_new_window(window->mlx_ptr, 500, 500, "Main");

    mlx_key_hook(window->window_ptr, deal_key, (void *)window);
    mlx_loop(window->mlx_ptr);

    return 0;
} 
