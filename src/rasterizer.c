/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:17:21 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/02 14:03:16 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "int2.h"

#include <mlx.h>

#include <math.h> // For M_PI

// TODO big-endian support

void	put_pixel(t_framebuf *buf, t_int2 coord, unsigned int color)
{
	int				color_bytes;
	unsigned int	offset;

	color_bytes = buf->color_depth / 8; 
	offset = coord.x * color_bytes + coord.y * buf->width;
	if (buf->color_depth == 32)
		*(unsigned int*)(buf->data + offset) = color;
	if (buf->color_depth == 16)
		*(unsigned short*)(buf->data + offset) = color & 0xFFFF;
}

void	draw_line(t_framebuf *buf, t_int2 a, t_int2 b, unsigned int color)
{
	t_int2	dif;
	t_int2	out;
	t_int2	tmp;

	if (a.x > b.x)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	dif = int2_sub(b, a);
	out.x = a.x;
	while (out.x <= b.x)
	{
		out.y = a.y + dif.y * (out.x - a.x) / dif.x;
		put_pixel(buf, out, color);
		out.x++;
	}
}

int	render_hook(void *param)
{
	t_window *const		win = param;

	t_int2 a = {win->width / 2, win->height / 2};
	t_int2 b = {a.x + 256, a.y + 256};

	mlx_clear_window(win->mlx, win->mlxwin);
	draw_line(&win->buf, a, b, mlx_get_color_value(win->mlx, 0x00FFFFFF));
	mlx_put_image_to_window(win->mlx, win->mlxwin, win->mlximg, 0, 0);
	return (1);
}
