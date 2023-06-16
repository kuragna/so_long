#include "../include/so_long.h"

int	check_file_path(char *file_path)
{
	if (ft_strncmp(file_path, "maps/", 5) == 0)
	{
		file_path = ft_strrchr(file_path, '.');
		if (file_path == NULL || ft_strncmp(file_path, ".ber", 4) == 0)
			return (0);
	}
	return (1);
}
