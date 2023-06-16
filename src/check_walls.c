#include "../include/so_long.h"

int	check_walls(char **lines, int size)
{
	char	*first;
	char	*last;
	int		len;
	int		i;

	i = -1;
	first = lines[0];
	last = lines[size - 1];
	len = ft_strlen(last) - 1;
	if (size < 5 || size == len)
		return (1);
	while ((*first && *first != '\n') && (*last && *last != '\n'))
	{
		if (*first != '1' || *last != '1')
			return (1);
		first++;
		last++;
	}
	while (++i < size - 1)
	{
		if (lines[i][0] != '1' || lines[i][len - 1] != '1')
			return (1);
	}
	return (0);
}
