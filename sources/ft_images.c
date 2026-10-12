/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 18:58:25 by mabenois          #+#    #+#             */
/*   Updated: 2026/09/16 23:21:11 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

t_img_data	*ft_alloc_img_data(void)
{
	t_img_data	*new;

	new = malloc(sizeof(t_img_data));
	if (!new)
		return (NULL);
	new->width = 0;
	new->height = 0;
	new->img = NULL;
	new->addr = NULL;
	new->bpp = -1;
	new->line_length = -1;
	new->endian = -1;
	return (new);
}

t_img_data	*ft_new_img(void *mlx, int width, int height)
{
	t_img_data	*new;

	new = ft_alloc_img_data();
	if (!new)
		return (NULL);
	new->width = width;
	new->height = height;
	new->img = mlx_new_image(mlx, width, height);
	if (new->img == NULL)
	{
		free(new);
		return (NULL);
	}
	new->addr = mlx_get_data_addr(new->img, &new->bpp,
			&new->line_length, &new->endian);
	if (new->addr == NULL)
	{
		mlx_destroy_image(mlx, new->img);
		free(new);
		return (NULL);
	}
	return (new);
}

void	ft_free_img(void *mlx, t_img_data *img)
{
	mlx_destroy_image(mlx, img->img);
	free(img);
}
