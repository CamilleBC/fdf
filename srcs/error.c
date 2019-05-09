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

void error_fdf(t_fdf *fdf, char *error_msg)
{
	if (fdf != NULL)
		free_fdf(fdf);
	if (error_msg != NULL)
		write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	else
		perror("The following error occured");
	exit(EXIT_FAILURE);
}
