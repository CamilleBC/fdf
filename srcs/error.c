/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 09:13:53 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/07 09:25:04 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

int check_error(int result)
{
    if (result < 0)
    {
        perror("The following error occured");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int check_null(void *result)
{
    if (result == NULL)
    {
        perror("The following error occured");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
