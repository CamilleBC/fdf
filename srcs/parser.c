/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 08:42:46 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/07 14:00:15 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "error.h"
#include "fdf.h"

int read_map(const char *path) {
    int     fd;
	char	*line;
    int     status;
    t_map   *map;

    if (check_error(fd = open(path, O_RDONLY)) == EXIT_FAILURE)
        return EXIT_FAILURE;
	while ((status = get_next_line(0, &line)) > FILE_READ)
	{

	}
	free(line);
    return status;
}

int parse_line(char *line, t_map map){
	if (*line == '\0')
		return EXIT_FAILURE;
}