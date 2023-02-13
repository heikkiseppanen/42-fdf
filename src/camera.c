/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:31:54 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/13 12:55:24 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	cam_init(t_cam *empty, float fov, int is_ortho)
{
	empty->fov = fov;
	empty->orthographic = is_ortho;
	empty->near = 0.1;
	empty->far = 100;
	empty->view_matrix = float4x4_id();
	empty->view_matrix.c.z = -1.0;
}

void	cam_calc_view(t_cam *camera, const t_transform *transform)
{
	t_float3	target;
	t_float4x4	rotation_matrix;

	target = (t_float3){ 0.0f, 0.0f, -1.0f };
	rotation_matrix = float4x4_rotation(&transform->rotation); 
	target = float3_transform(&rotation_matrix, &target);
	target = float3_add(&transform->position, &target);
	camera->view_matrix = float4x4_view(&transform->position, &target);
}
