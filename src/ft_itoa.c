/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Natalia <Natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:02:30 by nandreev          #+#    #+#             */
/*   Updated: 2024/05/27 15:28:55 by Natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	nlen(long ndup)
{
	int	len;

	len = 1;
	if (ndup < 0)
	{
		len++;
		ndup *= -1;
	}
	while (ndup > 9)
	{
		ndup /= 10;
		len++;
	}
	return (len);
}

static void	put_n(long ndup, char *result, int len)
{
	int	i;

	i = 0;
	if (ndup < 0)
	{
		result[i] = '-';
		ndup *= -1;
	}
	while (ndup != 0)
	{
		result[len - i - 1] = ndup % 10 + '0';
		ndup /= 10;
		i++;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	long	ndup;

	ndup = n;
	len = nlen(ndup);
	result = malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (NULL);
	if (n == 0)
		result[0] = '0';
	put_n(ndup, result, len);
	result[len] = '\0';
	return (result);
}
