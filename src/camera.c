/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:31:54 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/20 09:37:28 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

#include "input.h"

#include <math.h>

void	cam_init(t_cam *empty, float fov, int is_ortho)
{
	empty->is_ortho = is_ortho;
	empty->ortho_scale = 1.0;
	empty->ortho_size = 100;
	empty->fov = fov;
	empty->aspect = 1.0;
	empty->near = 0.1;
	empty->far = 100;
}

void	cam_update(t_cam *camera, t_transform *transform, t_input *input)
{
	const float	mouse_x = input->mouse_movement.x * input->mouse_sens;
	const float	mouse_y = input->mouse_movement.y * input->mouse_sens;

	camera->is_ortho = !input->projection_mode;
	if (input->rotate)
	{
		transform->position = float3_rot_y(transform->position, mouse_x);
	}
	if (input->zoom)
	{
		camera->ortho_scale += mouse_y;
		camera->ortho_scale = clamp(camera->ortho_scale, 0.1, 3.0);
		camera->fov += mouse_y;
		camera->fov = clamp(camera->fov, rad(1), rad(110));
	}
}

t_float4x4	cam_calc_projection(const t_cam *view)
{
	float	ortho_fov;

	if (view->is_ortho)
	{
		ortho_fov = view->ortho_scale * view->ortho_size;
		return (float4x4_ortho(ortho_fov, view->aspect, view->near, view->far));
	}
	else
	{
		return (float4x4_persp(view->fov, view->aspect, view->near, view->far));
	}
}

t_float4x4	cam_calc_view(const t_transform *transform)
{
	const t_float3	target = (t_float3){0.0f, 0.0f, 0.0f};

	return (float4x4_view(transform->position, target));
}
