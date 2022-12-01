/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:26:07 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/01 11:25:28 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RASTERIZER_H
# define RASTERIZER_H

#include "window.h"

typedef struct s_framebuf
{
	void	*mlx_img;
	char	*data;
	int		pixel_bits;
	int		line_width;
	int		endian;
} t_framebuf;

int		framebuf_init(t_window *win);
void	framebuf_destroy(t_framebuf *buf);

void	draw_line(t_framebuf buf, t_int2 a, t_int2 b)

#endif
