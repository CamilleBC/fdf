/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:52:17 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/07 12:33:56 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "parser.h"
#include "error.h"

int main (int argc, char *argv[])
{ 
    t_fdf   *fdf;
    int     status;

    if (argc != 1)
        return EXIT_FAILURE;

    status = EXIT_SUCCESS;
    fdf = NULL;
    if ((status = init_fdf_struct(&fdf)) == EXIT_FAILURE)
        return status;
    // if ((status = read_map(fdf->map, argv[1])) == EXIT_FAILURE
    //     || (status = draw_map(fdf->map, fdf->window) == EXIT_FAILURE))
    if ((status = draw_map(fdf) == EXIT_FAILURE))
        free_fdf_struct(fdf);
    return status;
} 

int init_fdf_struct(t_fdf **fdf_ptr)
{
    t_fdf   *fdf;

    if (check_null(fdf = (t_fdf *)malloc(sizeof(t_fdf))) == EXIT_FAILURE)
        return EXIT_FAILURE;
    *fdf_ptr = fdf;
    fdf->map = NULL;
    fdf->window = NULL;
    if (check_null(fdf->window = (t_window *)malloc(sizeof(t_window)))
            == EXIT_FAILURE)
        return EXIT_FAILURE;
    fdf->window->mlx_ptr = NULL;
    fdf->window->window_ptr = NULL;
    if (check_null(fdf->map = (t_map *)malloc(sizeof(t_map))) == EXIT_FAILURE)
        return EXIT_FAILURE;
    fdf->map->array = NULL;
    
    return EXIT_SUCCESS;
}

void free_fdf_struct(t_fdf *fdf)
{
    if (fdf->map != NULL)
    {
        if(fdf->map->array != NULL)
            free(fdf->map->array);
        free(fdf->map);
    }
    if (fdf->window != NULL)
    {
        if(fdf->window->mlx_ptr != NULL)
            free(fdf->window->mlx_ptr);
        free(fdf->window);
    }
}
