/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:52:15 by hseppane          #+#    #+#             */
/*   Updated: 2023/11/11 12:04:21 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

#include "window.h"
#include "rendering.h"

#include <mlx.h>

int	app_init(t_app *empty, char *mesh_path)
{
	if (!window_init(&empty->window, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF")
		|| !scene_init(&empty->scene, mesh_path))
	{
		return (0);
	}
	mlx_loop_hook(empty->window.mlx_handle, app_mlx_loop, empty);
	mlx_hook(empty->window.mlx_window, ON_DESTROY, 0, app_terminate, empty);
	input_init(&empty->input, empty->window.mlx_window);
	return (1);
}

int	app_terminate(t_app *instance, int exit_code)
{
	scene_del(&instance->scene);
	window_del(&instance->window);
	exit(exit_code);
	return (1);
}

int	app_mlx_loop(t_app *app)
{
	t_window *const	window = &app->window;
	t_scene *const	scene = &app->scene;
	t_input *const	input = &app->input;

	scene_update(scene, input);
	input->mouse_movement.x = 0;
	input->mouse_movement.y = 0;
	draw_mesh(&window->framebuffer, &scene->mesh, &scene->scene_matrix);
	window_swap_buf(window);
	if (input->exit)
	{
		app_terminate(app, 0);
	}
	return (1);
}
