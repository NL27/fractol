/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:43:14 by nlenoch           #+#    #+#             */
/*   Updated: 2021/10/21 10:35:32 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	key_hook(int key)
{
	if (key == ESC_KEY)
		exit(0);
	return (0);
}

int	zoom(int key, int x, int y, t_data *data)
{
	x = 0;
	y = 0;
	if (key == SCROLL_UP)
	{
		data->max_x -= (data->max_x / 4);
		data->max_y -= (data->max_y / 4);
		data->min_x -= (data->min_x / 4);
		data->min_y -= (data->min_y / 4);
	}
	if (key == SCROLL_DOWN)
	{
		data->max_x += (data->max_x / 4);
		data->max_y += (data->max_y / 4);
		data->min_x += (data->min_x / 4);
		data->min_y += (data->min_y / 4);
	}
	mlx_clear_window(data->mlx.mlx, data->mlx.win);
	create(data);
	return (0);
}
