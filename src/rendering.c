/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:03:07 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/11 20:00:10 by hseppane         ###   ########.fr       */
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
	const float	ortho_fov = tanf(view->fov / 2) * view->far;
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

static t_float4x4	calc_view(const t_cam *scene_view)
{
	
}

int	render_scene(const t_scene *scene, t_framebuf *target_buffer)
{
	t_float4x4	matrix;

	framebuf_clear(target_buffer);
	matrix = float4x4_mul();
	dynarr_del(&vertices);
}
