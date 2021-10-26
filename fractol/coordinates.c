/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:04:36 by nlenoch           #+#    #+#             */
/*   Updated: 2021/10/21 15:43:06 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_data	coordinates(double w, double h, t_data *data)
{	
	data->x = w / (WIDTH / (data->max_x - data->min_x)) + data->min_x;
	data->y = h / (H / (data->max_y - data->min_y)) * -1 + data->max_y;
	if (data->type == '1')
	{
		data->Cx = data->x;
		data->Cy = data->y;
	}
	return (*data);
}
