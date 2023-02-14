/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:03:07 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/14 14:12:38 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

#include "window.h"
#include "scene.h"
#include "ft_math.h"

#include <libft.h>
#include <math.h>

static t_float4x4	calc_projection(const t_cam *view, const t_framebuf *buffer)
{
	const float aspect_ratio = (float)buffer->width / (float)buffer->height;
	const float	ortho_fov = tanf(view->fov / 2) * (view->far / 2);
	//const float	ortho_fov = tanf(view->fov / 2) * view->far;

	if (view->orthographic)
	{
		return (float4x4_ortho(ortho_fov, aspect_ratio, view->near, view->far));
	}
	else
	{
		return (float4x4_persp(view->fov, aspect_ratio, view->near, view->far));
	}
}

static t_float4x4	calc_scene_matrix(const t_scene *scene, t_framebuf *buffer)
{
	
}

int	render_scene(const t_scene *scene, t_framebuf *target_buffer)
{
	const t_float4x4	scene_matrix = calc_scene_matrix(scene, target_buffer);

	framebuf_clear(target_buffer);
}

