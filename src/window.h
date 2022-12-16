/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:59:55 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/16 14:12:27 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

typedef struct s_framebuf
{
	char	*data;
	int		color_bytes;
	int		width;
	int		height;
	int		endian;
} t_framebuf;

typedef struct s_window
{
	void	*mlx;
	void	*mlxwin;
	void	*mlximg;
	int		width;
	int		height;
	t_framebuf	buf;
} t_window;

enum e_window_event_type
{
	ON_DESTROY = 17,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6
};

int		window_init(t_window *win, int width, int height, char *title);
void	window_destroy(t_window *win);

void	window_swap_buf(t_window *win);

void	framebuf_clear(t_framebuf *buf);

#endif
