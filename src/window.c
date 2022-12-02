/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:59:25 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/02 11:46:44 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>
#include <input.h>

#include <mlx.h>

static int	framebuf_init(t_framebuf *buf, void *mlximg)
{
	int bits;
	int width;
	int endian;

	buf->data = mlx_get_data_addr(mlximg, &bits, &width, &endian);
	if (!buf->data)
		return (0);
	buf->color_depth = bits;
	buf->width = width;
	buf->endian = endian;
	return (1);
}

int	window_init(t_window *win, int width, int height, char *title)
{
	win->mlx = mlx_init();
	if (!win->mlx)
		return (0);
	win->mlxwin = mlx_new_window(win->mlx, width, height, title);
	if (!win->mlxwin)
		return (0);
	win->mlximg = mlx_new_image(win->mlx, win->width, win->height);
	if (!win->mlximg)
		return (0);
	if (!framebuf_init(&win->buf, win->mlximg))
		return (0);
	win->width = width;
	win->height = height;
	return (1);
}

#ifdef __linux__

void	window_destroy(t_window *win)
{
	mlx_destroy_image(win->mlx, win->mlximg);
	mlx_destroy_window(win->mlx, win->mlxwin);
	mlx_destroy_display(win->mlx);
	win->mlx= 0;
	win->mlxwin = 0;
	win->mlximg = 0;
	win->width = 0;
	win->height = 0;
}

#else

void	window_destroy(t_window *win)
{
	mlx_destroy_image(win->mlx, win->mlximg);
	mlx_destroy_window(win->mlx, win->mlxwin);
	win->mlx = 0;
	win->mlxwin = 0;
	win->mlximg = 0;
	win->width = 0;
	win->height = 0;
}

#endif
