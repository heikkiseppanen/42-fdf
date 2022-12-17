/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:14:29 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/17 09:55:11 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include "ft_math.h"

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

void	draw_line(t_framebuf *buf, t_int2 a, t_int2 b, unsigned int color)
{
	t_int2 dif;
	t_int2 s;
	int		err;
	int		e2;
	
	dif.x = abs(b.x - a.x); 
	dif.y = -abs(b.y - a.y);
	s.x = -1 + (2 * (a.x < b.x));
	s.y = -1 + (2 * (a.y < b.y));
	err = dif.x + dif.y;
	while (a.x != b.x || a.y != b.y)
	{
		put_pixel(buf, a, color);
		e2 = 2 * err;
		if (e2 >= dif.y)
		{
			err += dif.y;
			a.x += s.x;
		}
		if (e2 <= dif.x)
		{
			err += dif.x;
			a.y += s.y;
		}
	}
}
