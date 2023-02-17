/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:14:29 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/17 11:01:27 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

static void	put_pixel(t_framebuf *buf, t_int2 pos, unsigned int color)
{
	int	offset;

	if (pos.x < 0 || pos.y < 0 || pos.x >= buf->width || pos.y >= buf->height)
		return ;
	offset = pos.x * buf->color_bytes + pos.y * buf->width * buf->color_bytes;
	if (buf->color_bytes == 4)
		*(unsigned int*)(buf->data + offset) = color;
	else if (buf->color_bytes == 2)
		*(unsigned short*)(buf->data + offset) = color & 0xFFFF;
}

static int	ft_abs(int i)
{
	return (i * ((i > 0) - (i < 0)));
}

// Bresenham line algorithm variation that tracks

void	draw_line(t_framebuf *buf, t_int2 a, t_int2 b, unsigned int color)
{
	const t_int2 delta = {ft_abs(b.x - a.x), -ft_abs(b.y - a.y)};
	const t_int2 direction = {-1 + (2 * (a.x < b.x)), -1 + (2 * (a.y < b.y))};
	int		error;
	int		err2;
	
	error = delta.x + delta.y;
	while (a.x != b.x || a.y != b.y)
	{
		put_pixel(buf, a, color);
		err2 = 2 * error;
		if (err2 >= delta.y)
		{
			error += delta.y;
			a.x += direction.x;
		}
		if (err2 <= delta.x)
		{
			error += delta.x;
			a.y += direction.y;
		}
	}
	put_pixel(buf, a, color);
}
