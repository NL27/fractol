/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:08:19 by nlenoch           #+#    #+#             */
/*   Updated: 2021/10/21 21:21:30 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	helpme(char *argv, int x)
{
	int	i;

	i = 0;
	while (x != 0)
	{
		if (ft_strchr(argv, '-') != NULL || ft_strchr(argv, '+') != NULL)
			i++;
		if (i > 1)
		{
			error1();
			exit(1);
		}
		argv++;
		x--;
	}
}

double	help(double num[2], int n, char *argv)
{
	double	result;

	result = 0.0;
	while (n != 0)
	{
		num[1] = num[1] / 10;
		n--;
	}
	if (argv[0] != '-')
		result = num[0] + num[1];
	else
		result = num[0] - num[1];
	return (result);
}

double	atod(char *argv)
{
	char	**part;
	double	result;
	double	num[2];
	int		n;
	int		x;

	result = 0.0;
	if (ft_strchr(argv, '.') != ft_strrchr(argv, '.')
		|| ft_strchr(argv, '.') == NULL || *(ft_strchr(argv, '.') + 1) == '\0')
	{
		error1();
		exit(1);
	}
	if (ft_strchr(argv, '.') != NULL)
	{
		part = ft_split(argv, '.');
		n = ft_strlen(part[1]);
		x = ft_strlen(part[0]);
		helpme(argv, x);
		num[0] = (double)ft_atoi(part[0]);
		num[1] = (double)ft_atoi(part[1]);
		result = help(num, n, argv);
		ft_free(part);
	}
	return (result);
}

void	ft_free(char **part)
{
	int	n;

	n = 0;
	while (part[n] != NULL)
	{
		free(part[n]);
		n++;
	}
	free(part);
}
