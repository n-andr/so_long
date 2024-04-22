/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:23:12 by nandreev          #+#    #+#             */
/*   Updated: 2024/04/22 20:39:05 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (check_map(argv[1]) == 0)
		{
			write(1, "Error\nMap is wrong\n", 20);
			exit(EXIT_FAILURE);
		}
	}
	else
		write(1, "Programm accepts only 1 argument\n", 33);
	exit(EXIT_SUCCESS);
}