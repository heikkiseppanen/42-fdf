/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:44:51 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/05 15:23:57 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_H
# define APP_H

#include "window.h"
#include "graphics.h"
#include "ft_math.h"

typedef struct s_app
{
	t_window 	win;
	t_mesh		map;
	t_float3	pos;
	t_float3	rot;
} t_app;

int		app_init(t_app *instance, char *map_path);
void	app_terminate(t_app *instance);

int		app_mlx_loop(void *params);

#endif
