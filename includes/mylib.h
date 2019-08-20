/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:58:27 by jterrell          #+#    #+#             */
/*   Updated: 2019/08/20 18:50:54 by jterrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLIB_H
# define MYLIB_H

typedef	struct		s_list
{
	struct s_list	*next;
	char		c;
}			t_list;

t_list *g_char_buf;
int g_str_count;
char g_empty_c;
char g_obstacle_c;
char g_full_c;
int g_strlen;
int **g_matrix;
int g_square_len;
int		g_j_s;
int		g_i_s;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

void ft_putchar(char c);
void ft_putstr(char *str);
int ft_g_strlen(char *str);
int ft_atoi(char *str);
void		print_error(char *str);
t_list *ft_open_file(char *filename, int *fd);
void ft_sep_first_string(t_list *buf, int *g_str_count, char *g_empty_c, char *g_obstacle_c, char *g_full_c);
int ft_g_matrix_size(t_list *buf);
int **ft_create_g_matrix(int h, int w);
void ft_fill_g_matrix(int **g_matrix, t_list *buf, int h, int w, char g_obstacle_c);
int ft_min2(int a, int b);
int ft_min3(int a, int b, int c);
void ft_calculate_matrix(int **matrix, int h, int w);
void ft_find_max_square(int *ii, int *jj, int *size);
void    print_res(int x, int y, int now, int max);
void	ft_free();
int		check(t_list *list);
int     check1(t_list *list);
t_list	*ft_create_elem(char data);
void	ft_list_push_back(t_list **begin_list, char data);
void     false_print(int i, int max);
void    excecutable_pipiska(int argc, int i);
void ft_calculate_g_matrix(int **g_matrix, int h, int w);

#endif
