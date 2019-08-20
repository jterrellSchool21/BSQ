/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 18:46:14 by jterrell          #+#    #+#             */
/*   Updated: 2019/08/20 18:55:02 by jterrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int		ft_min2(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int		ft_min3(int a, int b, int c)
{
	return (ft_min2(a, ft_min2(b, c)));
}

void	ft_calculate_g_matrix(int **g_matrix, int h, int w)
{
	int i;
	int j;

	i = 1;
	while (i < h)
	{
		j = 1;
		while (j < w)
		{
			if (g_matrix[i][j] == -1)
				g_matrix[i][j] = ft_min3(g_matrix[i][j - 1],\
						g_matrix[i - 1][j - 1], g_matrix[i - 1][j]) + 1;
			j++;
		}
		i++;
	}
}

void	ft_find_max_square(int *ii, int *jj, int *size)
{
	int i;
	int j;
	int max_size;

	i = 0;
	max_size = 0;
	while (i < g_str_count)
	{
		j = 0;
		while (j < g_strlen)
		{
			if (g_matrix[i][j] > max_size)
			{
				max_size = g_matrix[i][j];
				*ii = i;
				*jj = j;
			}
			else
				j++;
		}
		i++;
	}
	*size = max_size;
}

int		main(int argc, char **argv)
{ 
	int		fd;
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (argc >= 2)
	{
		while (i < argc)
		{
			if(!(g_char_buf = ft_open_file(argv[i], &fd)))
				false_print(i, argc);
			if (fd > 0)
			{
				ft_sep_first_string(g_char_buf, &g_str_count, &g_empty_c, &g_obstacle_c, &g_full_c);
				if (!(check1(g_char_buf)))
					false_print(i, argc);
				else
				{
					excecutable_pipiska(argc, i);
				}
			}
			i++;
		}
	}
	else 	
		ft_putstr("Wrong number of parameters.\n");
	return (0);
}
