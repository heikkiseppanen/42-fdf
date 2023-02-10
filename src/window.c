/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:59:25 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/09 11:32:32 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "input.h"

#include <libft.h> 
#include <mlx.h>

static int	framebuf_init(t_framebuf *empty, const t_window *context)
{
	int	bits;
	int	width;
	int	endian;

	empty->data = mlx_get_data_addr(context->mlx_image, &bits, &width, &endian);
	if (!empty->data)
		return (0);
	empty->color_bytes = bits / 8;
	empty->width = context->width;
	empty->height = context->height;
	empty->endian = endian;
	return (1);
}

int	window_init(t_window *empty, int width, int height, char *title)
{
	empty->mlx_handle = mlx_init();
	if (!empty->mlx_handle)
		return (0);
	empty->mlx_window = mlx_new_window(empty->mlx_handle, width, height, title);
	if (!empty->mlx_window)
		return (0);
	empty->mlx_image = mlx_new_image(empty->mlx_handle, width, height);
	if (!empty->mlx_image)
		return (0);
	if (!framebuf_init(&empty->framebuffer, empty))
		return (0);
	empty->width = width;
	empty->height = height;
	return (1);
}

void	framebuf_clear(t_framebuf *buf)
{
	ft_bzero(buf->data, buf->width * buf->height * buf->color_bytes);
}

void	window_swap_buf(t_window *win)
{
	mlx_put_image_to_window(
		win->mlx_handle,
		win->mlx_window,
		win->mlx_image, 0, 0);
}

void	window_del(t_window *win)
{
	mlx_destroy_image(win->mlx_handle, win->mlx_image);
	mlx_destroy_window(win->mlx_handle, win->mlx_window);
	win->mlx_image = NULL;
	win->mlx_window = NULL;
	win->width = 0;
	win->height = 0;
}
