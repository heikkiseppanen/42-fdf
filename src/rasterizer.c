/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:17:21 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/01 15:40:36 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

int		framebuf_init(t_framebuf *buf, const t_window *win)
{
	void			*img;
	unsigned char	*data;
	int				bits;
	int				width;
	int				endian;

	img = mlx_new_image(win->mlxptr, win->width, win->height);
	if (!img)
		return (0);
	data = mlx_get_data_addr(img, &bits, &width, &endian);
	if (!data)
		return (0);
	buf->mlx_img = img;
	buf->data = data;
	buf->pixel_bits = bits;
	buf->line_width = width;
	buf->endian = endian;
	return (1)
}
void	framebuf_destroy(t_framebuf *buf, const t_window *win);
{
	mlx_destroy_image(win->mlx_ptr, buf->mlx_img);
	buf->mlx_img = NULL;
	buf->data = NULL;
	buf->pixel_bits = 0;
	buf->line_width = 0;
	buf->endian = 0;
}

// TODO big-endian support

int	render_hook(void *param)
{
	t_window *const buf = param;
	mlx_clear_window(win.mlxptr, win.winptr);
	draw_line(
}

void	put_pixel(t_framebuf *buf, t_int2 coord, unsigned int color)
{
	int	i;
	int	bits; 

	i = coord.x + coord.y * buf->line_width;
	bits = buf->pixel_bits;
	while (bits--)
	{
		buf->data[i++] = (unsigned char)(color & 0xFF);
		color >>= 1;
	{
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
		x_out++;
	}
}

