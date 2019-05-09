/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 11:34:38 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/09 11:35:58 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int check_chars(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && !ft_isspace(line[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int check_map_x(t_map *map, char **split_line)
{
	int i;

	i = 0;
	while (split_line[i])
		i++;
	if (map->x == INVALID)
		map->x = i;
	else if (map->x != i)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
