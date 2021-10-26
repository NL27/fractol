/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:16:41 by nlenoch           #+#    #+#             */
/*   Updated: 2021/10/21 17:24:33 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	mandelbrot(t_data *data, int w, int h)
{
	int	n;

	n = 0;
	while (n < MAX_ITERATION)
	{	
		if (data->type == '3')
			data->illusion = -2 * fabs(data->x - data->y);
		else
			data->illusion = 2 * data->x * data->y;
		data->real = data->x * data->x - data->y * data->y;
		data->x = (data->real + data->Cx);
		data->y = (data->illusion + data->Cy);
		if ((data->x * data->x + data->y * data->y) > 4)
		{
			put_mlx_pixel(data, w, h, (n * 10) * 0x0000FF);
			break ;
		}
		n++;
	}
	return (n);
}
