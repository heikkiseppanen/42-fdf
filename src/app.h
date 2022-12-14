/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:44:51 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/14 17:17:48 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_H
# define APP_H

#include "window.h"
#include "graphics.h"

typedef struct s_app
{
	t_window		win;
	t_mesh			map;
	t_draw_param	gfx;
} t_app;

int	app_init(t_app *instance, char *map_path);
int	app_terminate(t_app *instance);

int	app_mlx_loop(void *params);

#endif
