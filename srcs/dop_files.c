/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:56:22 by jterrell          #+#    #+#             */
/*   Updated: 2019/08/20 18:37:14 by jterrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	while (*str != '\0')
		ft_putchar(*str++);
}

int ft_g_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

int ft_atoi(char *str)
{
	int res;
	int is_negativ;

	res = 0;
	is_negativ = 1;
	while ((*str == ' ' || *str == '\n' || *str == '\t') && *str != '\0')
		str++;
	if (*str == '-')
		is_negativ = -1;
	if(*str == '+' || *str == '-')
		str++;
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * is_negativ);
}

void		print_error(char *str)
{
	write(2, "bsq: ", 5);
	if (errno == 13)
	{
		ft_putstr(str);
		write(2, ": Permission denied\n", 20);
	}
	else if (errno == 2)
	{
		ft_putstr(str);
		write(2, ": No such file or directory\n", 28);
	}
	else if (errno == 21)
	{
		ft_putstr(str);
		write(2, ": Is a directory\n", 17);
	}
}
