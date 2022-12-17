/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:52:15 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/17 14:44:35 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "input.h"
#include "ft_math.h"

#include <libft.h>
#include <mlx.h>
#include <math.h> // for M_PI

static void gfx_init(t_draw_param *param, t_framebuf *buf)
{
	const	float	fov = M_PI / 2; 
	t_float3	view_pos = {20.0, 20.0, 20.0};
	t_float3	view_target = {0, 0, 0};

	param->pos= (t_float3){0.0, 0.0, 0.0};
	param->rot= (t_float3){0.0, 0.0, 0.0};
	param->scale = (t_float3){1.0, 0.3, 1.0};
	param->project = float4x4_ortho(fov*45, buf->height / buf->width, 0.1, 60);
	param->view = float4x4_view(&view_pos, &view_target);
}

static void input_init(t_input *input)
{
	input->movekey = 0;
	input->rotkey = 0;
	input->scroll_sens = 0.01;
	input->mouse_sens = 0.01;
	input->mouse_movement = (t_int2){0, 0};
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
	mlx_hook(instance->win.mlxwin, ON_MOUSEDOWN, 0, mousedown_hook, instance);
	mlx_hook(instance->win.mlxwin, ON_MOUSEUP, 0, mouseup_hook, instance);
	mlx_hook(instance->win.mlxwin, ON_MOUSEMOVE, 0, mousemove_hook, instance);
	gfx_init(&instance->gfx, &instance->win.buf);
	input_init(&instance->input);
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
	window_swap_buf(&app->win);
	return (1);
}
