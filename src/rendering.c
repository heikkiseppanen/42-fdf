/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:03:07 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/10 12:15:06 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

#include "scene.h"
#include "ft_math.h"

#include <math.h>

static t_float4x4	get_proj_mat(const t_cam *view, const t_framebuf *buffer)
{
	const float aspect_ratio = (float)buffer->width / (float)buffer->width;
	const float	clip_min = 0.1;
	const float	clip_max = 500;
	const float	ortho_size = tanf(fov / 2) * clip_max;

	if (scene_view->is_ortho)
		return (float4x4_ortho(ortho_size, aspect_ratio, clip_min, clip_max));
	else
		return (float4x4_persp(fov, aspect_ratio, clip_min, clip_max));
}

static t_float4x4	get_view_matrix(const t_cam *scene_view)
{
	
}

int	render_update(const t_scene *scene, t_framebuf *target_buffer)
{
	const t_float4x4	matrix;
	const t_dynarr		vertices;

	matrix = float4x4_mul();
}
