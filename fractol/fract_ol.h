/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:50:08 by nlenoch           #+#    #+#             */
/*   Updated: 2021/10/21 21:20:33 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# define WIDTH 1080
# define H 1080
# define ESC_KEY 53
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define MAX_ITERATION 150

# include "./mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

struct s_mlx
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*win;
};

typedef struct s_data
{
	struct s_mlx	mlx;
	double			x;
	double			y;
	double			real;
	double			illusion;
	double			Cx;
	double			Cy;
	double			max_y;
	double			max_x;
	double			min_y;
	double			min_x;
	char			type;
}				t_data;

int		mandelbrot(t_data *data, int w, int h);
int		key_hook(int key);
int		zoom(int key, int x, int y, t_data *data);
void	put_mlx_pixel(t_data *data, int x, int y, int color);
void	*create(t_data *data);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *c);
double	atod(char *argv);
char	**ft_split(char const *s, char c);
int		wcount(const char *s, char c);
char	**wlen(const char *s, int wc, char c, char **s1);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_atoi(const char *str);
void	init(t_data *data);
void	ft_free(char **part);
t_data	coordinates(double w, double h, t_data *data);
void	error1(void);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);

#endif