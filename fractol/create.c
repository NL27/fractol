/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:47:00 by nlenoch           #+#    #+#             */
/*   Updated: 2021/10/24 16:13:28 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	put_mlx_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->mlx.addr + (y * data->mlx.line_length + x
			* (data->mlx.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	*create(t_data *data)
{
	double	w;
	double	h;
	int		n;

	w = 0;
	n = 0;
	data->mlx.img = mlx_new_image(data->mlx.mlx, WIDTH, H);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bits_per_pixel,
			&data->mlx.line_length, &data->mlx.endian);
	while (w < WIDTH)
	{
		h = 0;
		while (h++ < H)
		{
			*data = coordinates(w, h, data);
			n = mandelbrot(data, w, h);
			if (n < 10)
				put_mlx_pixel(data, w, h, (n * 30) % 0x0000FF);
			h++;
		}
		w++;
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	mlx_destroy_image(data->mlx.mlx, data->mlx.img);
	return (NULL);
}
