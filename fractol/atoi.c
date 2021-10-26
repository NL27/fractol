/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:54:05 by nlenoch           #+#    #+#             */
/*   Updated: 2021/10/21 12:03:35 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if ((*str >= 65 && *str <= 90) || (*str >= 97 && *str <= 122))
		return (0);
	if ((*str) == '-' || (*str) == '+')
	{
		if (*str == '+')
			sign = 1;
		else
			sign = -1;
		++str;
	}
	while ((*str >= 48) && (*str <= 57))
	{
		result = (result * 10) + (*str - 48);
		str++;
	}
	return (sign * result);
}
