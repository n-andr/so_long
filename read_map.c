/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:23:28 by nandreev          #+#    #+#             */
/*   Updated: 2024/04/22 20:53:11 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int is_rectangular(char *map)
{
    
}

int check_map(char *map)
{
    int file;

    file = open(map, O_RDWR);

    if (!is_rectangular(map)) 
    {
        write(1, "Error\nMap is not rectangular\n", 29);
        return (0);
    }

    return (0); // if map is wrong
}