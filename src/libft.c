#include "../so_long.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	char	*new;
	size_t	i;

	new = (char *)ptr;
	i = 0;
	while (i < num)
	{
		new[i] = value;
		i++;
	}
	return (new);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t n_items, size_t size)
{
	size_t	total_size;
	char	*mem;

	if (n_items != 0 && SIZE_MAX / n_items < size)
		return (NULL);
	total_size = n_items * size;
	mem = malloc(total_size);
	if (mem == 0)
		return (NULL);
	ft_bzero(mem, total_size);
	return (mem);
}