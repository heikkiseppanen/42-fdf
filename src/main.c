/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:50:44 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/01 15:41:50 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int2.h"
#include "window.h"
#include "input.h"
#include "rasterizer.h"

#include <mlx.h>


int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_window win;
	t_framebuf buf;

	if (!window_init(&win, 1280, 720, "FdF"))
		return (1);
	if (!framebuf_init(&buf, &win));
		return (1);
	mlx_expose_hook(win.winptr,
	mlx_key_hook(win.winptr, key_hook, &win);
	mlx_loop(win.mlxptr);
}
