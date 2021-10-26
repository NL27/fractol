/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:49:48 by nlenoch           #+#    #+#             */
/*   Updated: 2021/10/21 21:20:07 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	int		i;
	char	*x;

	ch = (char)c;
	i = 0;
	x = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			x = (char *)&s[i];
		s++;
	}
	if (s[i] == ch)
		x = (char *)&s[i];
	return (x);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*uc1;
	unsigned char	*uc2;
	size_t			i;

	uc1 = (unsigned char *)s1;
	uc2 = (unsigned char *)s2;
	i = 0;
	if ((ft_strlen(s1) == 0 && ft_strlen(s2) == 0) || n == 0)
		return (0);
	if (ft_strlen(s1) == 0)
		return (-1);
	if (ft_strlen(s2) == 0)
		return (1);
	while ((i <= n && uc1[i] != '\0') || uc2[i] != '\0')
	{
		if ((uc1[i] == uc2[i] && i == n) || i == n)
			return (0);
		if (uc1[i] > uc2[i])
			return (1);
		if (uc1[i] < uc2[i])
			return (-1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *c)
{
	size_t	count;

	count = 0;
	while (*c != '\0')
	{
		count++;
		c++;
	}
	return (count);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}
