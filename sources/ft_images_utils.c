/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 23:19:17 by mabenois          #+#    #+#             */
/*   Updated: 2026/09/16 23:20:18 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0)
		return ;
	if (x > data->width || y > data->height)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	my_mlx_pixel_get(t_img_data *data, int x, int y)
{
	char	*dst;

	if (x < 0 || y < 0)
		return (-1);
	if (x > data->width || y > data->height)
		return (-1);
	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	return (*(unsigned int *)dst);
}

void	ft_image_draw_rec(t_img_data *data, int *i)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < i[3])
	{
		while (x < i[2])
		{
			my_mlx_pixel_put(data, i[0] + x, i[1] + y, i[4]);
			x++;
		}
		y++;
		x = 0;
	}
}

void	ft_image_draw_circle(t_img_data *data, int *i)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < i[3])
	{
		while (x < i[2])
		{
			if (ft_int_coord_dist(i[0] + (i[2] / 2), i[1] + (i[3] / 2),
					i[0] + x, i[1] + y) < i[2] / 2)
				my_mlx_pixel_put(data, i[0] + x, i[1] + y, i[4]);
			x++;
		}
		y++;
		x = 0;
	}
}

void	ft_clear_img(t_img_data *data, int width, int height, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < height)
	{
		while (x < width)
		{
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
}
