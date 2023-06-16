#include "../include/so_long.h"

int	check_c_e_p(char **lines, int size)
{
	int	i;
	int	j;
	int	err[3];

	i = 0;
	ft_memset(err, 0, sizeof(err));
	while (++i < size - 1)
	{
		j = 1;
		while (lines[i][j] && lines[i][j] != '\n')
		{
			if (lines[i][j] == 'E')
				err[0]++;
			else if (lines[i][j] == 'P')
				err[1]++;
			else if (lines[i][j] == 'C')
				err[2]++;
			j++;
		}
	}
	if (err[0] != 1 || err[1] != 1 || err[2] < 1)
		return (1);
	return (0);
}

