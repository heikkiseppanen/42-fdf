/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:59:25 by hseppane          #+#    #+#             */
/*   Updated: 2022/11/29 14:26:12 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>
#include <input.h>

#include <mlx.h>
int window_init(t_window *win, int width, int height, char *title)
{
	win->mlxptr = mlx_init();
	if (!win->mlxptr)
		return (0);
	win->winptr = mlx_new_window(win->mlxptr, width, height, title);
	if (!win->winptr)
		return (0);
	win->width = width;
	win->height = height;
	return (1);
}

void window_destroy(t_window *win)
{
	mlx_destroy_window(win->mlxptr, win->winptr);
#ifdef __linux__
	mlx_destroy_display(win->mlxptr);
#endif
	win->mlxptr = 0;
	win->winptr = 0;
	win->width = 0;
	win->height = 0;
}
