/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:27:03 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/17 14:50:19 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

#ifdef __linux__
# include "linux/keycodes.h"
#else
# include "macos/keycodes.h"
#endif

#include <math.h> // M_PI

int	key_hook(int keycode, void *param)
{
	t_app *const	app = param;

	if (keycode == KEY_ESCAPE)
	{
		app_terminate(app);
		exit(0);
	}
	return (1);
}

int	mousedown_hook(int button, int x, int y, void *param)
{
	t_app *const	app = param;

	(void)x;
	(void)y;
	if (button == MOUSE_LEFT) 
		app->input.movekey = 1;
	else if (button == MOUSE_RIGHT) 
		app->input.rotkey = 1;
	return (1);
}

int	mouseup_hook(int button, int x, int y, void *param)
{
	t_app *const	app = param;

	(void)x;
	(void)y;
	if (button == MOUSE_LEFT) 
		app->input.movekey = 0;
	else if (button == MOUSE_RIGHT) 
		app->input.rotkey = 0;
	return (1);
}

int	mousemove_hook(int x, int y, void *param)
{
	t_app *const	app = param;
	const t_int2	newpos = {x, y};

	app->input.mouse_movement = int2_sub(app->input.mouse_position, newpos);
	app->input.mouse_position = newpos;
	if (app->input.rotkey)
	{
		app->gfx.rot.y += app->input.mouse_movement.x * app->input.mouse_sens;
		if (app->gfx.rot.y > M_PI * 2 || app->gfx.rot.y < -M_PI * 2)
			app->gfx.rot.y = 0;
	}
	return (1);
}
