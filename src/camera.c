/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:31:54 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/16 12:04:03 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

#include <math.h>

void	cam_init(t_cam *empty, float fov, int is_ortho)
{
	empty->orthographic = is_ortho;
	empty->fov = fov;
	empty->aspect = 1.0;
	empty->near = 0.1;
	empty->far = 100;
}

t_float4x4	cam_calc_projection(const t_cam *view)
{
	float	ortho_fov;

	if (view->orthographic)
	{ 
		ortho_fov = view->far / 2;
		return (float4x4_ortho(ortho_fov, view->aspect, view->near, view->far));
	}
	else
	{
		return (float4x4_persp(view->fov, view->aspect, view->near, view->far));
	}
}

t_float4x4	cam_calc_view(const t_transform *transform)
{
	const t_float3 target = (t_float3){ 0.0f, 0.0f, 0.0f };

	return (float4x4_view(transform->position, target));
}
