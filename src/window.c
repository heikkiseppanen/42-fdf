/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:59:25 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/21 15:50:17 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "input.h"

#include <libft.h> 
#include <mlx.h>

static int	frame_init(t_frame *empty, const t_window *context)
{
	int	bits;
	int	width;
	int	endian;

	*empty = (t_frame){};
	empty->width = context->width;
	empty->height = context->height;
	empty->data = mlx_get_data_addr(context->mlx_image, &bits, &width, &endian);
	if (!empty->data)
		return (0);
	empty->depth_buffer = malloc(empty->width * empty->height * sizeof(float));
	if (!empty->depth_buffer)
		return (0);
	empty->color_bytes = bits / 8;
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
	empty->width = width;
	empty->height = height;
	if (!frame_init(&empty->framebuffer, empty))
		return (0);
	return (1);
}

void	frame_clear(t_frame *buf, unsigned int color)
{
	unsigned int *it = (unsigned int *)buf->data;
	unsigned int *end = it + buf->width * buf->height;

	while (it != end)
		*it++ = color;
	ft_bzero(buf->depth_buffer, buf->width * buf->height * sizeof(float));
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
	free(win->framebuffer.depth_buffer);
	*win = (t_window){};
}
