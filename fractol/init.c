/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:14:26 by nlenoch           #+#    #+#             */
/*   Updated: 2021/10/24 16:12:51 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	init(t_data *data)
{
	data->max_y = 2;
	data->max_x = 2;
	data->min_y = -2;
	data->min_x = -2;
}
