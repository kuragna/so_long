#include "../include/so_long.h"

void	print_map(char	**lines)
{
	int	i = 0;

	while (lines[i])
	{
		int	j = 0;
		while (lines[i][j])
		{
			printf("%c", lines[i][j]);
			j++;
		}
		i++;
	}
}
