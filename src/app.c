/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:52:15 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/05 15:40:06 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

#include "input.h"

#include "mlx.h"

int	app_init(t_app *instance, char *map_path)
{
	if (!window_init(&instance->win, 1280, 720, "FdF"))
		return (0);
	if (!mesh_load(&instance->map, map_path))
		return (0);
	mlx_key_hook(instance->win.mlxwin, key_hook, instance);
	mlx_loop_hook(instance->win.mlx, app_mlx_loop, instance);
	return (1);
}

void	app_terminate(t_app *instance)
{
	mesh_destroy(&instance->map);
	window_destroy(&instance->win);
}

int	app_mlx_loop(void *param)
{
	t_app *const	app = param;
	unsigned int	color;

	color = mlx_get_color_value(app->win.mlx, 0x00FFFFFF);
	draw_wireframe(&app->win.buf, &app->map, color);
	mlx_put_image_to_window(app->win.mlx, app->win.mlxwin, app->win.mlximg, 0, 0);
	return (1);
}
