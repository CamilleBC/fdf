/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 08:42:46 by cbaillat          #+#    #+#             */
/*   Updated: 2019/06/04 15:39:35 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "error.h"

/*
** This file holds all functions related to reading the map and saving it to a
** structure.
*/

void parse_map(t_fdf *fdf, const char *path)
{
	int   fd;
	int   i;
	char *line;
	int   status;

	if ((fd = open(path, O_RDONLY)) < 0)
		error_fdf(fdf, "error open");
	i = 0;
	while ((status = get_next_line(fd, &line)) > FILE_READ)
	{
		if (i % 10 == 0)
			if ((fdf->map->array = ft_realloc(fdf->map->array, i * sizeof(int *)
				, (i + 10) * sizeof(int *))) == NULL)
			{
				free(line);
				error_fdf(fdf, "error realloc");
			}
		parse_line(line, fdf, i);
		i++;
	}
	if (i == 0)
		error_fdf(fdf, "The map is empty.\n");
	else if (status < 0)
		error_fdf(fdf, "error gnl");
	fdf->map->height = i;
	free(line);
	close(fd);
}

void parse_line(char *line, t_fdf *fdf, int i)
{
	char	**split_line;
	// int		*points;

	split_line = NULL;
	if (*line == '\0' || *line == '\n'
		// || check_chars(line) == EXIT_FAILURE
		|| (split_line = ft_strsplit(line, ' ')) == NULL
		|| check_map_x(fdf->map, split_line) == EXIT_FAILURE
		|| (fdf->map->array[i] = parse_points(split_line, fdf)) == NULL)
	{
		if (split_line != NULL)
			free(split_line);
		error_fdf(fdf, "error parse line");
	}
}

int *parse_points(char **split_line, t_fdf *fdf)
{
	int  i;
	int  j;
	int *points;

	i = 0;
	while (split_line[i])
		i++;
	if ((points = (int *) malloc(i * sizeof(int))) == NULL)
		return NULL;
	j = 0;
	while (j < i)
	{
		points[j] = ft_atoi(split_line[j]);
		if (points[j] > fdf->zmax)
			fdf->zmax = points[j];
		j++;
	}
	return points;
}

/*DEBUG */
void print_map(t_map *map)
{
	printf("Map X: %d\n", map->width);
	printf("Map Y: %d\n", map->height);
	for (int i = 0; i < map->height; i++)
	{
		for (int j = 0; j < map->width; j++)
			printf("%d ", map->array[i][j]);
		printf("\n");
	}
}
