/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:10:46 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/10 21:48:52 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <mlx.h>
#include <unistd.h>
#include <fcntl.h>
#include "../libft/libft.h"

typedef	int	t_err;


#define EXTENSION ".ber"

void	check_extension(char *file_name)
{
	file_name += (strlen(file_name) - 4);
	if (strncmp(file_name, EXTENSION, 4))
	{
		perror("ERROR");
		exit(1);
	}
}

// 11111
// 10001
// 10001
// 10001
// 11111


// 0 for an empty space,
// 1 for a wall,
// C for a collectible,
// E for a map exit,
// P for the player’s starting position

t_err first_end(char *line)
{
	while (*line)
	{
		if (*line != '1' && *line != '\n')
		{
			perror("ERROR");
			return 1;
		}
		line++;
	}
	return 0;
}
int	main(int argc, char **argv)
{
	char	*file_name = argv[1];
	if (argc == 1)
	{
		perror("ERROR");
		return 1;
	}

	check_extension(file_name);

	int	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		perror("ERROR");
		return 1;
	}
	char	*line = get_next_line(fd);
	printf("%s", line);
	return 0;
}
