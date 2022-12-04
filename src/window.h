/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:59:55 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/04 20:02:56 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "graphics.h"

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

int window_init(t_window *win, int width, int height, char *title);
void window_destroy(t_window *win);

#endif
