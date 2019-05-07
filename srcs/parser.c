/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 08:42:46 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/07 17:47:04 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "error.h"
#include "fdf.h"

int read_map(t_map *map, const char *path)
{
    int     fd;
    int     i;
	char	*line;
    int     status;

    if (check_error(fd = open(path, O_RDONLY)) == EXIT_FAILURE)
        return EXIT_FAILURE;
	i = 0;
	while ((status = get_next_line(fd, &line)) > FILE_READ)
	{
		if (check_error(parse_line(line, map, i)) == EXIT_FAILURE)
			return EXIT_FAILURE;
		i++;
	}
	free(line);
    return status;
}

int parse_line(char *line, t_map *map, int map_index)
{
	char	**split_line;
	int		*points;

	if (*line == '\0')
		return EXIT_FAILURE;
	if ((check_null(split_line = ft_strsplit(line, ' '))) 
		== EXIT_FAILURE)
		return EXIT_FAILURE;
	points = get_points(split_line);
	
	return EXIT_SUCCESS;
}

int *get_points(char **split_line)
{
	int i;

	i = 0;
	while (split_line[i])
	{
		printf("array[%d]: %s\n", i, split_line[i]);
		i++;
	}
	return NULL;
}