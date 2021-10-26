/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:51:44 by nlenoch           #+#    #+#             */
/*   Updated: 2021/10/21 21:28:20 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	error1(void)
{
	perror("Usage: ./fractol 1 || 2 || 3");
	perror("1 = Mandelbrot");
	perror("2 = Juliaset & 2 point numbers between -2.0 & 2.0");
	perror("3 = Galaxy");
}

int	error2(int argc, char *argv[])
{
	double	n;
	double	m;

	if ((ft_strncmp(argv[1], "2", 1) == 0) && (argc < 4))
	{
		perror("Usage: ./fractol 2 and 2 point numbers between -2.0 & 2.0");
		return (0);
	}
	if (argc >= 4)
	{
		n = atod(argv[2]);
		if ((n < -2 || n > 2) && (ft_strncmp(argv[1], "2", 1) == 0))
		{
			perror("Usage: ./fractol 2 and 2 point numbers between -2.0 & 2.0");
			return (0);
		}
		m = atod(argv[3]);
		if ((m < -2 || m > 2) && (ft_strncmp(argv[1], "2", 1) == 0))
		{
			perror("Usage: ./fractol 2 and 2 point numbers between -2.0 & 2.0");
			return (0);
		}
	}
	return (1);
}

int	error_check(int argc, char *argv[])
{
	if (argc <= 1 || ((((ft_strncmp(argv[1], "2", 1) != 0)
					&& (argc < 5) && (ft_strncmp(argv[1], "1", 1) != 0)))
			&& (ft_strncmp(argv[1], "3", 1))))
	{
		error1();
		return (0);
	}
	else
		return (error2(argc, argv));
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!error_check(argc, argv))
		return (0);
	if (*argv[1] == '1' || *argv[1] == '3')
		data.type = *argv[1];
	else if (*argv[1] == '2')
	{
		data.type = '2';
		data.Cx = atod(argv[2]);
		data.Cy = atod(argv[3]);
	}
	init(&data);
	data.mlx.mlx = mlx_init();
	data.mlx.win = mlx_new_window(data.mlx.mlx, WIDTH, H, "Fractals");
	create(&data);
	mlx_hook(data.mlx.win, 2, 0, key_hook, &data);
	mlx_hook(data.mlx.win, 4, 0, zoom, &data);
	mlx_loop(data.mlx.mlx);
}
