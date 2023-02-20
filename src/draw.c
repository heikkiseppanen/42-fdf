/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:14:29 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/20 15:23:23 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

static void	put_pixel(t_framebuf *buf, t_int2 pos, t_float3 color)
{
	int	offset;
	unsigned int mlx_color;

	mlx_color = (unsigned char)(255 * color.x) << 16;
	mlx_color = (unsigned char)(255 * color.y) << 8 | mlx_color;
	mlx_color = (unsigned char)(255 * color.z) | mlx_color;
	if (pos.x < 0 || pos.y < 0 || pos.x >= buf->width || pos.y >= buf->height)
		return ;
	offset = pos.x * buf->color_bytes + pos.y * buf->width * buf->color_bytes;
	*(unsigned int*)(buf->data + offset) = mlx_color;
}

static int	ft_abs(int i)
{
	return (i * ((i > 0) - (i < 0)));
}

// Bresenham line algorithm variation that tracks

void	draw_line(t_framebuf *to, t_int2 a, t_int2 b, t_float3 c0, t_float3 c1)
{
	const t_int2	delta = {ft_abs(b.x - a.x), -ft_abs(b.y - a.y)};
	const t_int2	dir = {-1 + (2 * (a.x < b.x)), -1 + (2 * (a.y < b.y))};
	t_float3		color_offset;
	int				error;
	int				err2;
	
	if (!delta.x && !delta.y)
		return ;
	if (delta.x >= -delta.y)
		color_offset = float3_scalar(float3_sub(c1, c0), 1.0f / delta.x);
	else
		color_offset = float3_scalar(float3_sub(c1, c0), 1.0f / -delta.y);
	error = delta.x + delta.y;
	while (a.x != b.x || a.y != b.y)
	{
		put_pixel(to, a, c0);
		c0 = float3_add(c0, color_offset);
		err2 = 2 * error;
		error += delta.y * (err2 >= delta.y);
		a.x += dir.x * (err2 >= delta.y);
		error += delta.x * (err2 <= delta.x);
		a.y += dir.y * (err2 <= delta.x);
	}
	put_pixel(to, a, c0);
}
