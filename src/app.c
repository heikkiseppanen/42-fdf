/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:52:15 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/09 13:58:04 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "input.h"

#include <mlx.h>

#include <stdlib.h>

int	app_init(t_app *instance, char *map_path)
{
	if (!window_init(&instance->win, 512, 512, "FdF"))
		return (0);
	if (!mesh_load(&instance->map, map_path))
		return (0);
	mlx_key_hook(instance->win.mlxwin, key_hook, instance);
	mlx_loop_hook(instance->win.mlx, app_mlx_loop, instance);
	mlx_hook(instance->win.mlxwin, ON_DESTROY, 0, app_terminate, instance);
	return (1);
}

int	app_terminate(t_app *instance)
{
	mesh_destroy(&instance->map);
	window_destroy(&instance->win);
	exit(0);
	return (1);
}

int	app_mlx_loop(void *param)
{
	t_app *const	app = param;

	draw_wireframe(&app->win.buf, &app->map, 0x00FFFFFF);
	mlx_put_image_to_window(app->win.mlx, app->win.mlxwin, app->win.mlximg, 0, 0);
	return (1);
}
