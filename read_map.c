/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:23:28 by nandreev          #+#    #+#             */
/*   Updated: 2024/04/22 21:19:48 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int is_rectangular(char *map)
{
    write(1, "Error\nMap is not rectangular\n", 29);
    return (0);
}

int is_closed(char *map)
{
    write(1, "Error\nMap is not closed/surrounded by walls\n", 44);
    return (0);
}

int has_valid_path(char *map)
{
    write(1, "Error\nNo valid path\n", 21);
    return (0);
}

int check_map(char *map)
{
    int file;

    file = open(map, O_RDWR);
    if (file == -1)
	{
		write(1, "Error\nMap does not exist\n", 25);
		return (0);
	}
    is_rectangular(map);
    is_closed(map);
    has_valid_path(map);

    return (0); // if map is wrong
}