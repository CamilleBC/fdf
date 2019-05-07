/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 08:47:04 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/07 17:41:53 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

#include <fcntl.h>
#include "libft.h"
#include "fdf.h"

int *get_points(char **split_line);
int read_map(t_map *map, const char *path);

#endif /* PARSER_H */
