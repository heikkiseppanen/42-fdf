/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:17:21 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/04 21:05:18 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "float3.h"

#include <mlx.h>

#include <math.h> // For M_PI

// TODO big-endian support

void	put_pixel(t_framebuf *buf, t_float3 pos, unsigned int color)
{
	int	offset;

	if (pos.x < 0 || pos.y < 0 || pos.x >= buf->width || pos.y >= buf->height)
		return ;
	offset = (int)pos.x * buf->color_bytes + (int)pos.y * buf->width * buf->color_bytes;
	if (buf->color_bytes == 4)
		*(unsigned int*)(buf->data + offset) = color;
	if (buf->color_bytes == 2)
		*(unsigned short*)(buf->data + offset) = color & 0xFFFF;
}

void	draw_line(t_framebuf *buf, t_float3 a, t_float3 b, unsigned int color)
{
	t_float3	dif;
	t_float3	out;
	t_float3	tmp;

	if (a.x > b.x)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	dif = float3_sub(b, a);
	out.x = a.x;
	while (out.x <= b.x)
	{
		out.y = a.y + dif.y * (out.x - a.x) / dif.x;
		put_pixel(buf, out, color);
		out.x++;
	}
}

int	render_mesh(void *param)
{
	t_framebuf *const		win = param;

	t_float3 a = {win->width / 2, win->height / 2, 0};
	t_float3 line = {1, 256, 0};
	static double angle = 0;
	char *buf = win->buf.data;
	int size =  win->buf.height * win->buf.width * win->buf.color_bytes;

	while (size--)
		*buf++ = 0;
	mlx_clear_window(win->mlx, win->mlxwin);
	t_float3 b = float3_add(a, float3_rotate(line, angle));
	if (angle <= 2 * M_PI)
		angle += 0.05;
	else
		angle = 0;
	draw_line(&win->buf, a, b, mlx_get_color_value(win->mlx, 0x00FFFFFF));
	mlx_put_image_to_window(win->mlx, win->mlxwin, win->mlximg, 0, 0);
	return (1);
}
