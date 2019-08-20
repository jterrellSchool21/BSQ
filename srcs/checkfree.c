/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:41:42 by jterrell          #+#    #+#             */
/*   Updated: 2019/08/20 18:56:53 by jterrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mylib.h>

void	ft_free(void)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = 0;
	j = 0;
	while (i < g_str_count)
	{
		free(g_matrix[i]);
		i++;
	}
	free(g_matrix);
	while (g_char_buf)
	{
		tmp = g_char_buf;
		g_char_buf = g_char_buf->next;
		free(tmp);
	}
}

int		check(t_list *list)
{
	t_list	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = list;
	while (tmp->c != '\n')
	{
		i++;
		tmp = tmp->next;
	}
	tmp = tmp->next;
	i = 0;
	while (tmp->c != '\n')
	{
		i++;
		tmp = tmp->next;
	}
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->c != '\n')
			j++;
		else
		{
			if (i != j)
				return (0);
			j = 0;
		}
		tmp = tmp->next;
	}
	return (1);
}

int		check1(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp->c != '\n')
	{
		tmp = tmp->next;
	}
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->c != g_empty_c && tmp->c != g_obstacle_c && tmp->c != '\n')
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	false_print(int i, int max)
{
	if (i != max - 2)
	{
		ft_putstr("map error\n");
	}
	else
	{
		ft_putstr("map error\n");
		ft_putchar('\n');
	}
}
