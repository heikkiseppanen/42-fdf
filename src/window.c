/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:59:25 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/14 09:47:42 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "input.h"

#include <libft.h> 
#include <mlx.h>

static int	framebuf_init(t_framebuf *buf, t_window *win)
{
	int bytes;
	int width;
	int endian;

	buf->data = mlx_get_data_addr(win->mlximg, &bytes, &width, &endian);
	if (!buf->data)
		return (0);
	buf->color_bytes = bytes / 8;
	buf->width = win->width;
	buf->height = win->height;
	buf->endian = endian;
	return (1);
}

int	window_init(t_window *win, int width, int height, char *title)
{
	win->width = width;
	win->height = height;
	win->mlx = mlx_init();
	if (!win->mlx)
		return (0);
	win->mlxwin = mlx_new_window(win->mlx, win->width, win->height, title);
	if (!win->mlxwin)
		return (0);
	win->mlximg = mlx_new_image(win->mlx, win->width, win->height);
	if (!win->mlximg)
		return (0);
	if (!framebuf_init(&win->buf, win))
		return (0);
	return (1);
}

void	framebuf_clear(t_framebuf *buf)
{
	ft_bzero(buf->data, buf->width * buf->height * buf->color_bytes);
}

#ifdef __linux__

void	window_destroy(t_window *win)
{
	mlx_destroy_image(win->mlx, win->mlximg);
	mlx_destroy_window(win->mlx, win->mlxwin);
	mlx_destroy_display(win->mlx);
	win->mlx= 0;
	win->mlxwin = 0;
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
