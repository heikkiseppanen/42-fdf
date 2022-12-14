/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:27:03 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/14 16:00:48 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

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
	const float		rot_speed = 0.2;

	if (keycode == KEY_ESCAPE)
	{
		app_terminate(app);
		exit(0);
	}
	else if (keycode == KEY_LEFT)
	{
		if (app->gfx.rot.y > 2 * M_PI)
			app->gfx.rot.y = 0;
		app->gfx.rot.y += rot_speed;
	}
	else if (keycode == KEY_RIGHT)
	{
		if (app->gfx.rot.y < -2 * M_PI)
			app->gfx.rot.y = 0;
		app->gfx.rot.y -= rot_speed;
	}
	return (1);
}
