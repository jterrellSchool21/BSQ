/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osnova.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:57:23 by jterrell          #+#    #+#             */
/*   Updated: 2019/08/20 17:29:25 by jterrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

t_list *ft_open_file(char *filename, int *fd)//Прочитаем фаил и получим все из него
{
	t_list *ptr;
	char c;
	int i;
	int		fd1;

	fd1 = open(filename, O_RDWR);
	ptr = NULL;
	if (fd1 < 0)
	{
		print_error(filename);
		ft_putchar('\n');
	}
	else 
	{
		while(read(fd1, &c, 1) > 0)
			ft_list_push_back(&ptr, c);	
	}
	*fd = fd1;
	if (check(ptr))
		return (ptr);
	else
		return (0);
}

void ft_sep_first_string(t_list *buf, int *g_str_count, char *g_empty_c, char *g_obstacle_c, char *g_full_c)
{
	char *ptr;
	int i;
	t_list *head;
	
	ptr = (char*)malloc(sizeof(char) * 12);
	i = 0;
	head = buf;
	while (head->c >= '0' && head->c <= '9')
	{
		ptr[i] = head->c;
		head = head->next;
		i++;
	}
	*g_str_count = ft_atoi(ptr);
	*g_empty_c = head->c;
	head = head->next;
	*g_obstacle_c = head->c;
	head = head->next;
	*g_full_c = head->c;
}

int ft_g_matrix_size(t_list *buf)
{
	int i;
	t_list *s;

	i = 1;
	s = buf;
	while (s->c != '\n' && s) 
		s = s->next;
	s = s->next;// пропустим пробел
	while (s->c != '\n')
	{
		i++;
		s = s->next;
	}
	return (i);
}

int **ft_create_g_matrix(int h, int w)
{
	int **g_matrix;
	int i;
	int j;

	i = 0;
	g_matrix = (int**)malloc(sizeof(int*) * h);
	while (i < h)
		g_matrix[i++] = (int*)malloc(sizeof(int) * w);
	i = 0;
	while (i < h)	
	{
		j = 0;
		while (j < w)
		{
			g_matrix[i][j] = -1;
			j++;
		}
		i++;
	}
	return (g_matrix);
}

void ft_fill_g_matrix(int **g_matrix, t_list *buf, int h, int w, char g_obstacle_c)
{
	int i;
	int j;
	t_list *s;

	s = buf;
	while(s->c != '\n')
		s = s->next;
	s = s->next;
	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			if (s->c == g_obstacle_c)
				g_matrix[i][j] = 0;
			s = s->next;
			j++;
		}
		i++;
	}
	i = -1;
	while (++i < w)
		if (g_matrix[0][i] == -1)
			g_matrix[0][i] = 1;
	i = -1;
	while (++i < h)
		if (g_matrix[i][0] == -1)
			g_matrix[i][0] = 1;
}
