/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:50:44 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/04 21:28:27 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "window.h"
#include "input.h"
#include "graphics.h"

#include <mlx.h>


int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_window win;

	if (!window_init(&win, 1280, 720, "FdF"))
		return (1);
	mlx_key_hook(win.mlxwin, key_hook, &win);
	mlx_loop_hook(win.mlx, render_hook, &win);
	mlx_loop(win.mlx);
}
