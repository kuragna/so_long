/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:09:26 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/15 17:37:22 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <math.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <mlx.h>
# include "../libft/libft.h"

int		check_walls(char **lines, int size);
int		check_file_path(char *file_path);
int		check_c_e_p(char **lines, int size);
void	print_map(char **lines);

#endif
