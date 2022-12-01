/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:59:25 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/01 15:41:50 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>
#include <input.h>

#include <mlx.h>

int	window_init(t_window *win, int width, int height, char *title)
{
	win->mlxptr = mlx_init();
	if (!win->mlxptr)
		return (0);
	win->winptr = mlx_new_window(win->mlxptr, width, height, title);
	if (!win->winptr)
		return (0);
	if (!framebuf_init(
	win->width = width;
	win->height = height;
	return (1);
}

#ifdef __linux__

void	window_destroy(t_window *win)
{
	mlx_destroy_window(win->mlxptr, win->winptr);
	mlx_destroy_display(win->mlxptr);
	win->mlxptr = 0;
	win->winptr = 0;
	win->width = 0;
	win->height = 0;
}
#else

void	window_destroy(t_window *win)
{
	mlx_destroy_window(win->mlxptr, win->winptr);
	win->mlxptr = 0;
	win->winptr = 0;
	win->width = 0;
	win->height = 0;
}
#endif
