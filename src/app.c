/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:52:15 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/13 14:10:03 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "input.h"

#include <mlx.h>

#include <math.h> // for M_PI

static void gfx_init(t_draw_params *params, t_window *win)
{
	const	t_float3 ortho_bounds = {5.0, 50.0, win->height / win->width * 5.0};
	const	t_float3 view_pos = {20, -20, 20};
	const	t_float3 view_rot = {0.0, M_PI/4, -M_PI}; 

	params->position = (t_float3){0.0, 0.0, 0.0};
	params->rotation = (t_float3){0.0, 0.0, 0.0};
	params->scale = (t_float3){1.0, 1.0, 1.0};
	params->projection = float4x4_ortho(&ortho_bounds);
	params->view = float4x4_view(&view_pos, &view_rot);
}

int	app_init(t_app *instance, char *map_path)
{
	ft_bzero(instance, sizeof(*instance));
	if (!window_init(&instance->win, 512, 512, "FdF"))
		return (0);
	if (!mesh_from_map(&instance->map, map_path))
		return (0);
	mlx_key_hook(instance->win.mlxwin, key_hook, instance);
	mlx_loop_hook(instance->win.mlx, app_mlx_loop, instance);
	mlx_hook(instance->win.mlxwin, ON_DESTROY, 0, app_terminate, instance);
	gfx_init(&instance->gfx, &instance->win);
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

	draw_wireframe(&app->win.buf, &app->map, &app->gfx);
	mlx_put_image_to_window(app->win.mlx, app->win.mlxwin, app->win.mlximg, 0, 0);
	return (1);
}
