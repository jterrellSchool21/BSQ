/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 18:06:30 by jterrell          #+#    #+#             */
/*   Updated: 2019/08/20 18:55:21 by jterrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

void	excecutable_pipiska(int argc, int i)
{
	g_strlen = ft_g_matrix_size(g_char_buf);
	g_matrix = ft_create_g_matrix(g_str_count, g_strlen);
	ft_fill_g_matrix(g_matrix, g_char_buf, g_str_count, g_strlen, g_obstacle_c);
	ft_calculate_g_matrix(g_matrix, g_str_count, g_strlen);
	ft_find_max_square(&g_i_s, &g_j_s, &g_square_len);
	print_res(g_i_s, g_j_s, i, argc);
	ft_free();
}
