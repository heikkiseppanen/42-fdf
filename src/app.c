/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:52:15 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/14 19:16:13 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "input.h"
#include "ft_math.h"

#include <libft.h>
#include <mlx.h>
#include <math.h> // for M_PI

static void gfx_init(t_draw_param *param, t_window *win, t_mesh *mesh)
{
	const	t_float3	view_pos = {0, 0, 0};
	const	t_float3	view_rot = {M_PI / 4, 0.3, 0.0}; 
	t_float3	ortho_bounds;

	ortho_bounds.x = (mesh->width + mesh->depth) / 2;
	ortho_bounds.y = ortho_bounds.x * (win->height / win->height);
	ortho_bounds.z = ortho_bounds.x;
	param->pos= (t_float3){0.0, 0.0, 0.0};
	param->rot= (t_float3){0.0, 0.0, 0.0};
	param->scale = (t_float3){1.0, 1.0, 1.0};
	param->project = float4x4_ortho(&ortho_bounds);
	param->view = float4x4_view(&view_pos, &view_rot);
}

int	app_init(t_app *instance, char *map_path)
{
	ft_bzero(instance, sizeof(*instance));
	if (!window_init(&instance->win, 1024, 1024, "FdF"))
		return (0);
	if (!mesh_from_map(&instance->map, map_path))
		return (0);
	mlx_key_hook(instance->win.mlxwin, key_hook, instance);
	mlx_loop_hook(instance->win.mlx, app_mlx_loop, instance);
	mlx_hook(instance->win.mlxwin, ON_DESTROY, 0, app_terminate, instance);
	gfx_init(&instance->gfx, &instance->win, &instance->map);
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

	framebuf_clear(&app->win.buf);
	draw_wireframe(&app->win.buf, &app->map, &app->gfx);
	mlx_put_image_to_window(app->win.mlx, app->win.mlxwin, app->win.mlximg, 0, 0);
	return (1);
}
