/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 08:47:04 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/09 16:38:56 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

#include "fdf.h"
#include "libft.h"
#include <fcntl.h>

/*
** Checker
*/
int check_chars(char *line);
int check_map_x(t_map *map, char **split_line);
/*
** Parser
*/
void parse_line(char *line, t_fdf *fdf, int i);
void parse_map(t_fdf *fdf, const char *path);
int *parse_points(char **split_line);

#endif /* PARSER_H */
