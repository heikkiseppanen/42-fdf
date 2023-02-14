/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:14:29 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/14 14:57:07 by hseppane         ###   ########.fr       */
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
	if (buf->color_bytes == 2)
		*(unsigned short*)(buf->data + offset) = color & 0xFFFF;
}

// Bresenham line algorithm variation that tracks

void	draw_line(t_framebuf *buf, t_int3 a, t_int3 b, unsigned int color)
{
	t_int2	delta;
	t_int2	direction;
	int		error;
	int		err2;
	
	delta.x = abs(b.x - a.x); // REWRITE ABS
	delta.y = -abs(b.y - a.y);
	direction.x = -1 + (2 * (a.x < b.x));
	direction.y = -1 + (2 * (a.y < b.y));
	error = delta.x + delta.y;
	while (a.x != b.x || a.y != b.y)
	{
		put_pixel(buf, a, color);
		err2 = 2 * error;
		if (err2 >= direction.y)
		{
			error += direction.y;
			a.x += direction.x;
		}
		if (err2 <= direction.x)
		{
			error += direction.x;
			a.y += direction.y;
		}
	}
}
