/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:52:15 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/06 14:57:14 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

#include "input.h"
#include "ft_math.h"

#include <libft.h>
#include <mlx.h>

int	app_init(t_app *empty, char *mesh_path)
{
	if (!window_init(&empty->window, 1024, 1024, "FdF")
		|| !scene_init(&empty->scene, mesh_path))
	{
		return (0);
	}
	mlx_loop_hook(empty->window.mlx, app_mlx_loop, empty);
	mlx_hook(empty->window.mlxwin, ON_DESTROY, 0, app_terminate, empty);
	input_init(&empty->input);
	return (1);
}

int	app_terminate(t_app *instance, int exit_code)
{
	scene_del(&instance->scene);
	window_del(&instance->window);
	exit(exit_code);
	return (1);
}

int	app_mlx_loop(void *param)
{
	t_app *const	app = param;

	scene_update(&app->scene, &app->input);
	render_scene(&app->win.buf, &app->scene);
	window_swap_buf(&app->win);
	return (1);
}
