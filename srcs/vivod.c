/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vivod.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 15:20:15 by jterrell          #+#    #+#             */
/*   Updated: 2019/08/20 16:37:45 by jterrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

void	print_res(int x, int y, int now, int max)
{
	int		i;
	int		j;

	while (g_char_buf->c != '\n')
	{
		g_char_buf = g_char_buf->next;
	}
	g_char_buf = g_char_buf->next;
	i = 0;
	while (i < g_str_count)
	{
		j = 0;
		while (j < g_strlen)
		{
			if (j < y + 1 && j > y - g_square_len && i < x + 1 && i > x - g_square_len)
				ft_putchar(g_full_c);
			else
			{
				ft_putchar(g_char_buf->c);
				
			}
			g_char_buf = g_char_buf->next;
			j++;
		}
		i++;
	}
	if (now != max - 1)
		ft_putchar('\n');
}

